#include "Team2.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Character.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <typeinfo>
#include <utility>
#include <list>
using namespace std;
using namespace ariel;

Team2 ::Team2(Character *leader) : Team(leader) {}
void Team2 ::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
    {
        throw invalid_argument("Null Pointer");
    }
    if (enemyTeam == this)
    {
        throw runtime_error("The team can't attack himself ");
    }
    if (enemyTeam->stillAlive() == 0)
    {
        throw runtime_error("Cannot attack a dead team");
    }
    if (stillAlive() == 0)
    {
        throw runtime_error("the team is dead");
    }
    if (!(getLeader()->isAlive()))
    {
        setNextLeader();
    }
    Character *target = find_a_target(enemyTeam);
    for (const auto member : getMember())
    {
        if (!target->isAlive())
        {
            if (enemyTeam->stillAlive() == 0)
            {
                return;
            }

            target = find_a_target(enemyTeam);
        }
        Cowboy *cb = dynamic_cast<Cowboy *>(member);
        if (cb != nullptr && cb->isAlive())
        {
            if (cb->hasboolets())
            {
                cb->shoot(target);
            }
            else
                cb->reload();
        }
        else
        {
            Ninja *nj = dynamic_cast<Ninja *>(member);

            if (nj == nullptr)
            {
                continue;
            }
            
            if (!nj->isAlive())
                continue;
            if (nj->distance(target) <= 1.0)
            {
                nj->slash(target);
            }

            else
            {
                nj->move(target);
            }
        }
    }
}

void Team2 ::print()
{
    for (const auto &member : getMember())
    {
        cout << member->print() << endl;
    }
}