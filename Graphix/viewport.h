#include"graphics.h"


class Viewport{
    private:
        double ViewX1;
        double ViewY1;
        double ViewX2;
        double ViewY2;

        //Canvas c;

    public:
        Viewport(double xmin, double ymin, double xmax, double ymax){
            ViewX1 = xmin;
            ViewY1 = ymin;
            ViewX2 = xmax;
            ViewY2 = ymax;
            
        }
        Viewport();
        void Draw(double x1, double y1, double x2, double y2, Canvas &c, color cl);
        void ViewportToCanvas(double, double, double, double, double &, double &);
        void getXYMin(double &x, double &y){ x= ViewX1; y = ViewY1;}
        void geyXYMax(double &x, double &y){ x= ViewX2; y = ViewY2;}

        void Draw(double X1, double Y1, double X2, double Y2, Canvas &c, int quadrant, color cl);


        void Save(std::string, Canvas &c);

        

};

void Viewport::Draw(double X1, double Y1, double X2, double Y2, Canvas &c, color cl){
    double Width = c.Width();
    double Height = c.Height();

 
    

    double x1, y1, x2, y2;

    //Convert Coridnates to Canvas numbers
    ViewportToCanvas(X1, Y1, Height, Width, x1, y1);
    ViewportToCanvas(X2, Y2, Height, Width, x2, y2);

    printf("drawing from %d, %d to %d, %d \n", x1,y1,x2,y2);

    Line(c, x1, y1, x2, y2, cl);
    //SaveCanvasToFile(c, "BetterWork.pbm");


}

void Viewport::Draw(double X1, double Y1, double X2, double Y2, Canvas &c, int quadrant, color cl){
    

    double Width = c.Width();
    double Height = c.Height();

    if((X1 < ViewX1) || (Y1 < ViewY1) || (X2 > ViewX2) || (Y2 > ViewY2)){
        printf("X1 = %f, Viewx1 = %f \n", X1, ViewX1);
        printf("Y1 = %f, ViewY1 = %f \n", Y1, ViewY1);
        printf("X2 = %f, Viewx2 = %f \n", X2, ViewX2);
        printf("Y2 = %f, ViewY2 = %f \n", Y2, ViewY2);
        printf("returning\n");
        return;
    }


    double x1, y1, x2, y2;
    

    ViewportToCanvas(X1, Y1, Height/2, Width/2, x1, y1);
    ViewportToCanvas(X2, Y2, Height/2, Width/2, x2, y2);

    //Convert Coridnates to Canvas numbers
    switch(quadrant){
        case 1:
            x1 = x1 + (Width/2);
            x2 = x2 + (Width/2);
            break;
        case 2:
            break;
        case 3:
            y1 = y1 + (Height/2);
            y2 = y2 + (Height/2);
            break;
        case 4:
            x1 = x1 + (Width/2);
            y1 = y1 + (Height/2);
            x2 = x2 + (Width/2);
            y2 = y2 + (Height/2);
            break;                        
    }


   // printf("drawing from %d, %d to %d, %d \n", x1,y1,x2,y2);

    Line(c, x1, y1, x2, y2, cl);
    //SaveCanvasToFile(c, "BetterWork.pbm");


}



void Viewport::ViewportToCanvas(double vx, double vy, double height, double width, double &cx, double &cy){
    // scaling factors
    double sx = width/(ViewX2-ViewX1);
    double sy = -height/(ViewY2-ViewY1);

    //conversion
    cx = (vx - ViewX1)*sx;
    cy = ((vy - ViewY1)*sy) + height;

    printf("converted view(%f, %f) to can(%d,%d) \n", vx, vy, cx, cy);


}


void Viewport::Save(std::string filename, Canvas &c){
    SaveCanvasToFile(c, filename);
}

Viewport::Viewport(){

}