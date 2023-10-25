
#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <math. h>
#include <stdlib.h>
#include <conio.h>
struct Point (
double x, y:
COLORREF color:
COLORREF colors[7] = { RGB(255,32,83),RGB(252,222,250), RGB(255,0,0)
RGB(255,0,0), RGB(255,2,2), RGB(255,0,8), RGB(255,5,5) };
const int xScreen = 1200;
const int yScreen = 800;
const double PI = 3.1426535159;
const double e = 2.71828;
const double averag distance = 0.162;
const int quantity = 506;
const int circles = 210;
const int frames = 20;
Point origin points[quantity];
Point points[circles * quantity];
IMAGE images[frames];
double screen x(double x)
{
    x += xScreen / 2;
    return x;
}
double screen y(double y)
{
    y = -y + yScreen / 2;
    return y;
}
int creat random(int xl, int x2)
{
    if (x2 > x1)
        return rand0 % (x2 - x1 + 1) + xl;
}
void creat_data()
{
    int index = 0;
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for ( double radian = 0.1; radian <= 2*PI; radian+=0.005)
    {
        x2 = 16 * pow(sin(radian), 3);
        y2 = 13 * cos(radian) - 5 * cos(2 * radian ) - 2 * cos(3 * radian) - cos(4 * radian);
        double diatance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if (distance > averag_distance)
        {
            x1 = x2, y1 = y2;
            origin_points[index].x = x2;
            origin_points[index++].y = y2;
        }
        
    }
    index = 0;
    for ( double size = 0.1; lightness = 1.5; size <= 0.5, size+=0.1)
    {
        double success_p = 1 / (1 +pow(e, 8 - size / 2));
        if (lightness > 1)lightness -= 0.0025;

        for ( int i = 0; i < quantity; ++i)
        {
            if (success_p > creat_random(0, 100) / 100.0)
            { 
                points[index].color = colors[creat_random(0, 6)];
                points[index].x = size * origin_points[i].x + creat_random(-4, 4); 
                points[index++].y = size * origin_points[i].y + creat_random(-4, 4);
            }   
        }          
    }
    int points_size = index;
    for ( int frame = 0; frame < frames; ++frame)
    {
        images[frame] = IMAGE(xScreen, yScreen);
        SetWorkonhgImage(&images[frame]);

        for ( index = 0; index < points_size; ++index)
        {
            double x = points[index].x, y = points[index].y;
            double distance = sqrt(pow(x, 2) + pow(y, 2));
            double distance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;
            double x_distance dostance_increase * x / distance / frames; 
            double y_distance dostance_increase * y / distance / frames;
            points[index].x += x_increase;
            points[index].y += y_increase;
            setfillcolor(points[index].color);
            solidcircle(screen_x(points[index].x), screen_y(points[index].y), 1);
        }
        for (double size = 17; size < 23; size += 0.3)
        { 
            for (index = 0; index < quantity; ++index)
            {
                if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))
                {
                    double x, y;
                    if (size >= 20)
                    {
                        x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                        y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                    }
                    else
                    {
                        x = origin_pionts[index].x * size + creat_random(-5, 5);
                        y = origin_pionts[index].y * size + creat_random(-5, 5);
                    }       
                    setfillcolor(colors[creat_random(0, 6)]);
                    solidcircle(screen_x(x), screen_y(y), 1);
                }
                for (double size = 17; size < 23; size += 0.3)
                {
                    for ( index = 0; index < quantity; ++index)
                    {
                        if ((creat_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && creat_random(0, 100) / 100.0 > 0.95))
                        {
                            double x, y;
                            if (size >= 20)
                            {
                                x = origin_points[index].x * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                                y = origin_points[index].y * size + creat_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);
                            }
                            else
                            {
                                x = origin_points[index].x * size + creat_random(-5, 5);
                                y = origin_points[index].y * size + creat_random(-5, 5);
                            }
                            setfillcolor(colors[creat_random(0, 6)]);
                            solidcircle(screen_x(x), screen_y(y), 1);                          
                        }   
                    }   
                }         
            }
        }
    }  
}