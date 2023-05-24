#include "Ninja.hpp"
#include <iostream>
using namespace std; 
using namespace ariel;
Ninja :: Ninja(std::string name , Point location , int hitPoints ,int speed ) :Character(location,std :: move(name),hitPoints),speed(speed){}
void Ninja :: move(Character *enemy){
    if (enemy == nullptr)
    {
        throw invalid_argument("Can't move to a null enemy ");
    }
    if (enemy == this)
    {
        throw invalid_argument("Can't move to yourself ");
    }
    if (! (enemy->isAlive()))
    {
        throw runtime_error("The enemy is already dead ");
    }
    if (! (this->isAlive()))
    {
        throw runtime_error("The ninja is dead ");
    }
    //this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
    double dist=getLocation().distance(enemy->getLocation());
    double move_x=(enemy->getLocation().getX()-getLocation().getX())*(speed/dist);
    double move_y=(enemy->getLocation().getY()-getLocation().getY())*(speed/dist);
    setLocation(Point((double)(getLocation().getX()+move_x),(double)(getLocation().getY()+move_y)));
}
void Ninja :: slash(Character *enemy){
    if (enemy == nullptr )
    {
        throw invalid_argument("Can't slash to a null enemy ");
    }
    if (enemy == this)
    {
        throw invalid_argument("Can't slash yourself ");
    }
    if (! (enemy->isAlive()))
    {
        throw runtime_error("The enemy is already dead ");
    }
    if (! (this->isAlive()))
    {
        throw runtime_error("The ninja is dead ");
    }
    if (this->getLocation().distance(enemy->getLocation()) <= 1.0 )
    {
        enemy->hit(40);
    }
}
std :: string Ninja :: print() const{
    if (! this->isAlive())
    {
        return "Name: ("+getName() + ") , (Location: "+ getLocation().print()+")";
    }
    return "Name: ("+getName() + ") , (Location: "+ getLocation().print()+") , (HitPoints : "+to_string(getHitPoints())+")";
}
int Ninja :: getSpeed()
{
    return this->speed;
}
void Ninja :: setSpeed(int speed)
{
    this->speed=speed;
}


