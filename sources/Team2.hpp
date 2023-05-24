#ifndef TEAM2_HPP
#define TEAM2_HPP

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

class Team2 : public Team {
public:
    Team2(Character* leader);
    void attack(Team* enemyTeam) override;
    void print() override;
};

#endif // TEAM2_HPP