#include<iostream>
//#include"graphics.h"
//using namespace std;
#include"newFunctions.h"
#include<math.h>
const double segments = 100;

void InitGraphics(Viewport &v, Window &w);

int main(){
    Viewport v;
    Window w(0,0,0,0);
    Canvas c(1346, 1346);

    InitGraphics(v,w);

    //Function 1, Continuous
    w.moveTo(0,5.0);
    w.drawTo(0,-2.0, v, c, colors::BLACK);
    w.moveTo(-1.0, 0);
    w.drawTo(5.0, 0, v, c, colors::BLACK);

    double segLegnth = 3.0*M_PI / segments;
    double currentX = 0;
    w.moveTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)));

    for(int i = 0; i < segments; i++){
        w.drawTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)), v, c, colors::RED);
        currentX = currentX + segLegnth;
    }
    v.Save("Func1.pbm", c);

    c.Clear();

    //function 1, Segmented
    w.moveTo(0,5.0);
    w.drawTo(0,-2.0, v, c, colors::BLACK);
    w.moveTo(-1.0, 0);
    w.drawTo(5.0, 0, v, c, colors::BLACK);

    segLegnth = 3.0*M_PI / segments;
    currentX = 0;
    w.moveTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)));
    for(int i = 0; i < segments; i++){
        if(i%2 == 0){
            w.drawTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)), v, c, colors::RED);
            currentX = currentX + segLegnth;
        }
        else{
            w.moveTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)));
            currentX = currentX + segLegnth;
        }
    }
    v.Save("Func1-dash.pbm", c);

    c.Clear();

    //func 2, continuous
    w.setWindow(-6.5, -2, 6, 7);
    w.moveTo(0, 6.0);
    w.drawTo(0, -2.0, v, c, colors::BLACK);
    w.moveTo(-1.0, 0);
    w.drawTo(5.0, 0, v, c, colors::BLACK);

    segLegnth =  12.0 / segments;
    currentX = -6.0;
    w.moveTo(currentX, (3.0*pow(currentX,2) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0));
    for(int i = 0; i < segments; i++){
        w.drawTo(currentX, ((3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0)), v, c, colors::RED);
        currentX = currentX + segLegnth;
    }
    v.Save("Func2.pbm", c);

    c.Clear();

    //func 2, dash

    w.setWindow(-6.5, -2, 6, 7);
    w.moveTo(0, 6.0);
    w.drawTo(0, -2.0, v, c, colors::BLACK);
    w.moveTo(-1.0, 0);
    w.drawTo(5.0, 0, v, c, colors::BLACK);

    segLegnth =  12.0 / segments;
    currentX = -6;
    w.moveTo(currentX, (3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0));
    for(int i = 0; i < segments; i++){
        if(i%2 == 0){
            w.drawTo(currentX, ((3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0)), v, c, colors::RED);
            currentX = currentX + segLegnth;
        }
        else{
            w.moveTo(currentX, ((3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0)));
            currentX = currentX + segLegnth;
        }
    }
    v.Save("Func2-dash.pbm", c);

    c.Clear();

    //func 1 and 2 dashed on the same canvas
    //Function 1, Continuous
    w.setWindow(-6.5, -6.5, 6.5, 6.5);
    w.moveTo(0, 6.0);
    w.drawTo(0, -6.0, v, c, 1, colors::BLACK);
    w.moveTo(-6.0, 0);
    w.drawTo(6.0, 0, v, c, 1, colors::BLACK);

    segLegnth = 3.0*M_PI / segments;
    currentX = 0;
    w.moveTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)));

    for(int i = 0; i < segments; i++){
        w.drawTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)), v, c, 1, colors::RED);
        currentX = currentX + segLegnth;
    }
    

  


    //function 1, Segmented
    w.moveTo(0, 6.0);
    w.drawTo(0, -6.0, v, c, 2, colors::BLACK);
    w.moveTo(-6.0, 0);
    w.drawTo(6.0, 0, v, c, 2, colors::BLACK);

    segLegnth = 3.0*M_PI / segments;
    currentX = 0;
    w.moveTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)));
    for(int i = 0; i < segments; i++){
        if(i%2 == 0){
            w.drawTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)), v, c, 2, colors::RED);
            currentX = currentX + segLegnth;
        }
        else{
            w.moveTo(currentX, (3.0*pow(M_E, -0.33*currentX)*sin(3.0*currentX)));
            currentX = currentX + segLegnth;
        }
    }


    //func 2, continuous
    w.moveTo(0, 6.0);
    w.drawTo(0, -6.0, v, c, 3, colors::BLACK);
    w.moveTo(-6.0, 0);
    w.drawTo(6.0, 0, v, c, 3, colors::BLACK);

    segLegnth =  12.0 / segments;
    currentX = -6.0;
    w.moveTo(currentX, (3.0*pow(currentX,2) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0));
    for(int i = 0; i < segments; i++){
        w.drawTo(currentX, ((3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0)), v, c, 3 , colors::RED);
        currentX = currentX + segLegnth;
    }
  
    //func 2, dash

    
    w.moveTo(0, 6.0);
    w.drawTo(0, -6.0, v, c, 4, colors::BLACK);
    w.moveTo(-6.0, 0);
    w.drawTo(6.0, 0, v, c, 4, colors::BLACK);

    segLegnth =  12.0 / segments;
    currentX = -6;
    w.moveTo(currentX, (3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0));
    for(int i = 0; i < segments; i++){
        if(i%2 == 0){
            w.drawTo(currentX, ((3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0)), v, c, 4, colors::RED);
            currentX = currentX + segLegnth;
        }
        else{
            w.moveTo(currentX, ((3.0*pow(currentX,2.0) - 12.0*currentX -15.0) /(pow(currentX, 2.0) - 3.0*currentX -10.0)));
            currentX = currentX + segLegnth;
        }
    }

    v.Save("All-Functions.pbm", c);

    c.Clear();

    w.setWindow(-5, -5, 5, 5);



    /*
    w.moveTo(-3.0 ,-3.0);
    w.drawTo(3.0, 3.0, v, c, 1);
    w.moveTo(-3.0, 3.0);
    w.drawTo(3.0, -3.0, v, c, 1);

    w.moveTo(-3.0 ,-3.0);
    w.drawTo(3.0, 3.0, v, c, 2);
    w.moveTo(-3.0, 3.0);
    w.drawTo(3.0, -3.0, v, c, 2);

    w.moveTo(-3.0 ,-3.0);
    w.drawTo(3.0, 3.0, v, c, 3);
    w.moveTo(-3.0, 3.0);
    w.drawTo(3.0, -3.0, v, c, 3);

    w.moveTo(-3.0 ,-3.0);
    w.drawTo(3.0, 3.0, v, c, 4);
    w.moveTo(-3.0, 3.0);
    w.drawTo(3.0, -3.0, v, c, 4);
    
    v.Save("test.pbm", c);
    */

}

void InitGraphics(Viewport &v, Window &w){
    //Canvas c(1000, 1000, colors::BLACK);
    Viewport v1(-1.0, -1.0, 1.0, 1.0);
    
    Window w1(-1, -2, 5.0, 3.0);

    v = v1;
    w = w1;
}