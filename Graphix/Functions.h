#include"graphics.h"
#include<vector>


class Window{
    private:
    Canvas WinCanvas;
    
    public:
    Window(int, int);
    //SetWindow(int, int, color);   *??? not sure what to do with this LAMO
    void Translation2D(int x, int y); // Translate Point (
    void Scaling2D(int x, int y); // scale point
    void Rotation2D(int Radians);

    void saveWindow(std::string);

    void testLine(int x1, int y1, int x2, int y2, color c );


};

Window::Window(int width, int height){
    Canvas TempCanvas(width, height);
    WinCanvas = TempCanvas;
}

//Window InitGraphics(){
//    return Window (800, 800, colors::WHITE);
//}

void Window::Translation2D(int x, int y){      // the ways it's written right now, it will translate the whole world space lol
    //std::cout << "Strting Translation" << std::endl;
    int width = WinCanvas.Width();
    int height = WinCanvas.Height();
    pixel array[width][height];

    
    //std::cout << "starting frist for loop" << std::endl;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            array[i][j] = WinCanvas.GetPixel(i,j);
        }
    }

    WinCanvas.Clear();


    std::cout << "starting second for loop" << std::endl;
    for(int i = 0; i < width; i++){
       for(int j = 0; j < height; j++){
            if(i+x < width && i+x > 0 && j+y < height && j+y > 0);
                WinCanvas.SetPixel(i+x,j+y, array[i][j]);
        }
    }
    //std::cout << "Finised Tranlation" << std::endl;
}

void Window::Scaling2D(int x, int y){       //Should i just scale a point
    int width = WinCanvas.Width();          //???????? MIGHT JUST FUCK AROUND AND FIND OUT!!!!
    int height = WinCanvas.Height();
    pixel array[width][height];

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            array[i][j] = WinCanvas.GetPixel(i,j);
        }
    }

    WinCanvas.Clear();

    std::cout << "starting second for loop" << std::endl;
    for(int i = 0; i < width; i++){
       for(int j = 0; j < height; j++){
            
        }
    }
    //s

    

}


//for testing purpose only******************
void Window::saveWindow(std::string fileName){          
    SaveCanvasToFile(WinCanvas, fileName);
    
}

void Window::testLine(int x1, int y1, int x2, int y2, color c ){
    Line(WinCanvas, x1, y1, x2, y2, c);

}