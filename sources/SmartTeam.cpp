#include "Team2.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Character.hpp"
#include "SmartTeam.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <typeinfo>
#include <utility>
#include <list>
using namespace std;
using namespace ariel;

SmartTeam ::SmartTeam(Character *leader) : Team(leader) {}

Character* SmartTeam :: find_closest(Character* charcter , Team *enemyTeam)
{
    Character *closest=nullptr;
    double min=numeric_limits<double>::max();
    for(auto member : enemyTeam->getMember())
    {
        if (member->isAlive() && charcter)
        {
            int distance = charcter->distance(member);
            if (distance <min)
            {
                min=distance;
                closest=member;
            }
            
        }
        
    }
    return closest;
}
Character*  SmartTeam :: find_a_target(Team *enemyTeam)
{
    Character *ptarget = nullptr;
    int lessHp=numeric_limits<int>::max();
    for(auto member : enemyTeam->getMember())
    {
        if (member->isAlive())
        {
            if(lessHp > member->getHitPoints())
            {
                lessHp=member->getHitPoints();
                ptarget=member;
            }
        }
    }
    return ptarget;
}



void SmartTeam ::attack(Team *enemyTeam)
{
        if (enemyTeam == nullptr)
    {
        throw invalid_argument("Null Pointer");
    }
    else if (enemyTeam == this)
    {
        throw runtime_error("The team can't attack himself ");
    }
    else if (enemyTeam->stillAlive() == 0)
    {
        throw std::runtime_error("Cannot attack a dead team");
    }
    else if (this->stillAlive() == 0)
    {
        throw std::runtime_error("the team is dead");
    }
    else if (!(getLeader()->isAlive()))
    {
         Character *newleader = nullptr;
         double closestdistance = numeric_limits<double>::max();
         for (auto member : getMember())
          {
           double dist = getLeader()->distance(member);
           if (member->isAlive() && dist < closestdistance)
           {
            newleader = member;
            closestdistance = dist;
           }
         }
        setLeader(newleader);
    }
    Character *weaktarget = find_a_target(enemyTeam);
    vector<Ninja*> n;
    vector<Cowboy*>c;
    // cowboys
    for (auto &member : getMember())
    {
        Cowboy *cb = dynamic_cast<Cowboy *>(member);
        Ninja *nj = dynamic_cast<Ninja *>(member);
        if (cb != nullptr && cb->isAlive())
        {
            c.push_back(cb);
        }
        else if (nj !=nullptr && nj->isAlive())
        {
           n.push_back(nj);
        } 
    }    

    for (Cowboy* cowboy : c)
    {
        if (! weaktarget->isAlive())
        {
            if (enemyTeam->stillAlive()==0)
            {
                return;
            }
            weaktarget=find_closest(cowboy,enemyTeam);
        }
        if (cowboy->hasboolets())
        {
           cowboy->shoot(weaktarget);
        }
        else cowboy->reload();
    }
    for(Ninja* ninja : n)
    {
        if (enemyTeam->stillAlive()==0)
        {
            return;
        }
        weaktarget=find_closest(ninja,enemyTeam);
        if (ninja->distance(weaktarget) <= 1)
        {
            ninja->slash(weaktarget);
        }
        else ninja->move(weaktarget);
        
    }
            
}

void SmartTeam ::print()
{
    for (const auto &member : getMember())
    {
        cout << member->print() << endl;
    }
}