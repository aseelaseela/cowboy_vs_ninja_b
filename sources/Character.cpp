#include "Character.hpp"
#include <iostream>
using namespace std;
using namespace ariel;
Character :: Character(Point& nlocation , std :: string nname , int nhealth ) : location(nlocation),name(nname),inTeam(false),hitPoints(nhealth){}
bool Character ::isAlive() const{
    return (this->hitPoints>0) ? true : false ;
}
double Character :: distance(Character *other) const{
    return this->location.distance(other->location);
}
void Character :: hit (int hitNum){
    if (hitNum < 0)
    {
       throw invalid_argument("the number of hits can't be negitave");
    }
    if (hitNum > 0)
    {
        this->hitPoints-=hitNum;
    }
    else throw runtime_error("the character is already dead .. ");
}
string Character :: getName() const{
    return this->name;
}
const Point& Character :: getLocation()const{
    return this->location;
}
int Character :: getHitPoints()const{
    return this->hitPoints;
}
void Character :: setLocation(const Point& newlocation) {
    this->location=newlocation;
}
void Character :: setinTeam(bool inTeam){
    this->inTeam=!(this->inTeam);
}
void Character :: setName(const string& newName){
    name=newName;
}

