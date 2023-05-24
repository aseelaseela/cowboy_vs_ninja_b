#ifndef POINT_HPP
#define POINT_HPP
#include <string>
using namespace std;
namespace ariel
{
class Point
{
private:
    double x;
    double y;

public:
    Point(double x ,double y);
    Point();
    double distance (Point point) const;
    static Point moveTowards(const Point &source ,const Point &destination , double dist );
    std :: string print() const ;
    double getX() const ;
    double getY() const ;

};
}
#endif