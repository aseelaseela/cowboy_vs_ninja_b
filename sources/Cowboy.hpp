#ifndef COW_BOY_HPP
#define COW_BOY_HPP
#include "Character.hpp"
namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets=0;
    public:
        Cowboy(std::string name , const Point &location);
        ~Cowboy() override;

        //shoot the enemy ,substract 10 from the hitpoints 10 points 
        //cowboy should be alive and has bullets . 
        void shoot(Character *enemy);
        
        bool hasboolets() const;
        void reload();
        string print() const override;
    };
    
}
#endif