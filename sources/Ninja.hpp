#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;
    public:
        Ninja(std::string name , const Point &location , int health ,int speed ) ;
        ~Ninja(){};
        void move(Character *enemy);
        void slash(Character *enemy);
        std :: string print() const override;
        int getSpeed();
        void setSpeed(int speed);
    };    
}
#endif