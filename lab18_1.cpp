#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect r1, Rect r2) {
    double startX = (r1.x > r2.x) ? r1.x : r2.x;
    double endX = (r1.x + r1.w < r2.x + r2.w) ? r1.x + r1.w : r2.x + r2.w;
    double overlap_w = endX - startX;

    double y1_bottom = r1.y - r1.h;
    double y2_bottom = r2.y - r2.h;
    
    double startY = (y1_bottom > y2_bottom) ? y1_bottom : y2_bottom;
    double endY = (r1.y < r2.y) ? r1.y : r2.y;
    double overlap_h = endY - startY;

    if (overlap_w > 0 && overlap_h > 0) {
        return overlap_w * overlap_h;
    }
    return 0;
}
