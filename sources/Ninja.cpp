#include "Ninja.hpp"
#include <iostream>
using namespace std; 
using namespace ariel;
Ninja :: Ninja(std::string name , const Point &location , int hitPoints ,int speed ) :Character(location,std :: move(name),hitPoints),speed(speed){}
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
    Point newLocation = Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed);

    this->setLocation(newLocation);
}
void Ninja :: slash(Character *enemy){
    if (enemy == nullptr )
    {
        throw invalid_argument("Can't slash to a null enemy ");
    }
    if (enemy == this)
    {
        throw runtime_error("Can't slash yourself ");
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

