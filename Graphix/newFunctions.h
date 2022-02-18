#include<iostream>
#include"viewport.h"


class Window
{
private:
    double WinXmin;
    double WinYmin;
    double WinXmax;
    double WinYmax;
    double CurrentLocationX;
    double CurrentLocationY;

public:
    Window(double x1, double y1, double x2, double y2);
    ~Window();

    void setWindow(double x1, double y1, double x2, double y2){
        WinXmin = x1;
        WinYmin = y1;
        WinXmax = x2;
        WinYmax = y2;
    }

    void SetViewport(Viewport);

    // need to actually figure out how to convert
    void WindowToVeiwport(double wx, double wy, Viewport view, double &vx, double &vy);


    void moveTo(double x, double y);
    void drawTo(double x, double y, Viewport, Canvas &c, color cl);
    void drawTo(double x, double y, Viewport View, Canvas &c, int quadrant, color cl);
};


void Window::moveTo(double x, double y){
    CurrentLocationX = x;
    CurrentLocationY = y;
}

void Window::drawTo(double x, double y, Viewport View, Canvas &c, int quadrant, color cl){
    double ViewX1, ViewY1, ViewX2, ViewY2;

    // convert x and y to viewPort corrdinates
    WindowToVeiwport(CurrentLocationX, CurrentLocationY, View, ViewX1, ViewY1);
    WindowToVeiwport(x, y, View, ViewX2, ViewY2);

    View.Draw(ViewX1, ViewY1, ViewX2, ViewY2, c, quadrant, cl);

    //move
    CurrentLocationX = x;
    CurrentLocationY = y;

}

void Window::drawTo(double x, double y, Viewport View, Canvas &c, color cl){
    double ViewX1, ViewY1, ViewX2, ViewY2;

    // convert x and y to viewPort corrdinates
    WindowToVeiwport(CurrentLocationX, CurrentLocationY, View, ViewX1, ViewY1);
    WindowToVeiwport(x, y, View, ViewX2, ViewY2);

    View.Draw(ViewX1, ViewY1, ViewX2, ViewY2, c, cl);

    //move
    CurrentLocationX = x;
    CurrentLocationY = y;

}



void Window::WindowToVeiwport(double wx, double wy, Viewport view, double &vx, double &vy){
    double vxmin, vymin, vxmax, vymax;
    view.getXYMin(vxmin, vymin);
    view.geyXYMax(vxmax, vymax);

    printf("View min(%f, %f) --- View max(%f,%f) \n", vxmin, vymin, vxmax, vymax);

    // scaling factors
    double sx = (vxmax-vxmin)/(WinXmax-WinXmin);
    double sy = (vymax-vymin)/(WinYmax-WinYmin);

    //conversion
    vx = vxmin + (wx - WinXmin) * sx;
    vy = vymin + (wy - WinYmin) * sy;

    printf("converted win(%f, %f) to view(%f,%f) \n", wx, wy, vx, vy);

}


Window::Window(double x1, double y1, double x2, double y2)
{
    WinXmin = x1;
    WinYmin = y1;
    WinXmax = x2;
    WinYmax = y2;
}



Window::~Window()
{
}

//******************************************************************************************8
//Viewport


