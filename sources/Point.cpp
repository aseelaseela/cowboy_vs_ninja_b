#include "Point.hpp"
#include <cmath>
#include <iostream>
using namespace std;
using namespace ariel;
Point :: Point (double x , double y) :x(x) ,y(y) {}
Point :: Point () : x(0.0) , y(0.0) {}
double Point :: distance (Point point) const
{
    double dx=x-point.x;
    double dy=y-point.y;
    double res= sqrt(pow(dx,2)+pow(dy,2) );
    return res;
}
Point Point ::moveTowards(const Point &source ,const Point &destination , double dist ) 
{
    if (dist<0)
    {
        throw invalid_argument(" Can't move a negtive distance ! ");
    }
    double src_dest_distance=source.distance(destination);
    if (dist >= src_dest_distance)
    {
        return destination;
    }
    double dx=destination.x - source.x;
    double dy=destination.y - source.y;   
    double newx=source.x+(dist/src_dest_distance)*dx;
    double newy=source.y+(dist/src_dest_distance)*dy;
    return Point(newx,newy);
}
std :: string Point ::print()const 
{
    return "("+to_string(this->x)+","+ to_string(this->y)+")"; 
}
double Point :: getX() const { return this->x; }
double Point:: getY() const { return this->y; }