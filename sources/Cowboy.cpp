#include "Cowboy.hpp"
#include "Character.hpp"
#include <iostream>
using namespace std; 
using namespace ariel;
Cowboy :: Cowboy(std::string name , const Point &location) :bullets(6) , Character(location ,name , 110 ){}
Cowboy :: ~Cowboy()=default;
void Cowboy :: shoot(Character *enemy){
    if (enemy == nullptr)
    {
        throw invalid_argument("The enemy is can't be NULL .");
    }
    if (enemy == this)
    {
        throw runtime_error("The enemy can't be himself ");
    }
    if (!this->isAlive())
    {
        throw runtime_error("The cowboy is dead .");
    }
    if (!enemy->isAlive())
    {
        throw runtime_error("The enemy is dead .");
    }
    if (hasboolets())
    {
        enemy->hit(10);
        (this->bullets)--;
    }
}
bool Cowboy :: hasboolets() const{
    return this->bullets>0;
}
void Cowboy ::  reload(){
    if (!(this->isAlive()))
    {
        throw runtime_error("Cannot reload becouse cowboy is already dead ");
    }
    this->bullets=6;
}
string  Cowboy :: print()const {
    if (! isAlive())
    {
        return "Name : C ("+ getName() +"), Location: "+getLocation().print();
    }
    return "Name: C (" +getName() +",HitPoints " + to_string(getHitPoints())+"Location : "+getLocation().print();
}