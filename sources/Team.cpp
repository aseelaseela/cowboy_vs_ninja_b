#include "Team.hpp"
#include <vector>
#include<iostream>
#include<limits>
#include <algorithm>
#include<typeinfo>
#include <utility>
#include<list>
using namespace std; 
using namespace ariel;

Team :: Team(Character *leader) : leader(leader)
{
    if (leader->getInTeam())
    {
        throw runtime_error("the leader already in team ");
    }
    members.push_back(leader);
    leader->setinTeam(true);
}
void Team :: add(Character *member)
{
    if (member == nullptr)
    {
        throw invalid_argument("Member is null , didn't succeed to add ");
    }
    if (member->getInTeam())
    {
        throw runtime_error("Member is already in a team ");
    }
    if (members.size()==10)
    {
        throw runtime_error("Can't add the memer , the team is full ");
    }
    if (stillAlive()==0)
    {
        throw runtime_error("A dead team cannot attack");
    }
    
    members.push_back(member);
    member->setinTeam(true);    
}
void Team :: setNextLeader()
{
    Character *newleader=nullptr;
    double closestdistance=numeric_limits<double>::max();
    for(auto &member : members)
    {
        if (member->isAlive() && leader->distance(member) < closestdistance)
        {
            newleader=member;
            closestdistance=leader->distance(member);
        }   
    }
    leader=newleader;
}
Character* Team:: find_a_target(Team *enemyTeam)
{
    Character *ptarget=nullptr;
    double closestdistance=numeric_limits<double>::max();
    for(auto &member:enemyTeam->members)
    {
        if (member->isAlive() && leader->distance(member) < closestdistance)
        {
            ptarget=member;
            closestdistance=leader->distance(member);
        } 
    }
    return ptarget;
}
void Team :: attack(Team *enemyTeam)
{
    if (enemyTeam==nullptr)
    {
        throw invalid_argument( "Null Pointer");
    }
   else if (enemyTeam==this)
    {
        throw invalid_argument("The team can't attack himself ");
    }
   else if (enemyTeam->stillAlive()==0)
    {
        throw std::runtime_error("Cannot attack a dead team");
    }
    else if (this->stillAlive()==0)
    {
        throw std::runtime_error("the team is dead");
    }
    else if (!(leader->isAlive()))
    {
        setNextLeader();
    }
    Character *target =find_a_target(enemyTeam);
    //cowboys
    for (auto &member:members)
    {
        Cowboy *cb=dynamic_cast<Cowboy *>(member);
        if (cb != nullptr)
        {
            if(!cb->isAlive())continue;
            if (target->isAlive())
            {
                if (cb->hasboolets())
                {
                    cb->shoot(target);
                }
                else cb->reload();   
            }    
                else 
                {
                target=find_a_target(enemyTeam);
                if (target==nullptr)
                {
                    return;
                }
                else if (cb->hasboolets())
                {
                   cb->shoot(target);
                }
                else cb->reload();                
                }     
        } 
    }
    //ninjas
    for (auto &member:members)
    {
        Ninja *nj=dynamic_cast<Ninja *>(member);
        if (nj != nullptr)
        {
            if(!nj->isAlive())continue;
            if (target->isAlive())
            {
                if (nj->distance(target) <= 1.0 )
                {
                   nj->slash(target);
                }
                else nj->move(target);
            }
            else 
            {
                target=find_a_target(enemyTeam);
                if (target == nullptr)
                {
                   return;
                }
                else if (nj->distance(target) <= 1.0)
                {
                    nj->slash(target);
                }
                else nj->move(target);
            }
        }
    }
}
int Team :: stillAlive(){
    int count=0;
    for (Character *member:members)
    {
        if (member->isAlive())
        {
            count++;
        }
    }
    return count;
}
void Team :: print(){
    cout << "Team Leader : " << leader->getName() <<endl;
    for (auto &member:members)
    {
        if (dynamic_cast<Cowboy*>(member) != nullptr)
        {
            cout << member->print() <<endl ;
        }
    }
    for (auto &member:members)
    {
        if (dynamic_cast<Ninja*>(member) != nullptr)
        {
            cout << member->print() <<endl ;
        }
    }
}
Character* Team :: getLeader()
{
    return this->leader;

}
void Team :: setLeader(Character* newLeader)
{
    this->leader=newLeader;
}
std :: vector <Character*> Team :: getMember()
{
    return this->members;
}
Team :: ~Team(){
  /*  for (auto &member:members)
    delete member;
    members.clear();*/
}

