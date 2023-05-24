#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{
class Character
{
private:
    Point location;
    std :: string name;
    bool inTeam;
    int hitPoints;
public:
    Character(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator=(const Character& other);
    Character& operator=(const Character&& other) noexcept;

    Character(const Point &location , std :: string name , int health );
    Character();
    virtual ~Character(){} 

    //if the character is alive or not
    bool isAlive() const;

    //return the distance between the characters
    double distance(Character *other) const;

    //substract the number of hit points of the character
    void hit (int strength);
    string getName() const;
    void setName(const string& newName);
    const Point& getLocation()const;
    int getHitPoints()const;
    bool getInTeam(){return this->inTeam;}
    void setLocation(const Point& location);
    void setinTeam(bool inTeam);
    virtual std::string print() const=0;
};
}
#endif