#ifndef SMART_TEAM_NINJA_HPP
#define SMART_TEAM_NINJA_HPP
#include "Team.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <typeinfo>
#include <utility>
#include <list>
using namespace std;
using namespace ariel;
class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
        void attack(Team *enemyTeam) override;
        Character* find_a_target(Team *enemyTeam);
        Character* find_closest(Character* charcter , Team *enemyTeam);
        void print() override;
    };
#endif    
