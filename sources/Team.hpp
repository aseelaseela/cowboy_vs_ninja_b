#ifndef TEAM_HPP
#define TEAM_HPP
#include <vector>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;
namespace ariel
{
    class Team
    {
    private:
        Character *leader;
        std::vector<Character*>members;
    public:
        Team(Character *leader);
        virtual ~Team();
        void add(Character *member);
        virtual void attack(Team *enemyTeam);
        int stillAlive();
        virtual void print();
        Character* getLeader();
        void setLeader(Character* newLeader);
        void setNextLeader();
        std :: vector <Character*>getMember();
        Character* find_a_target(Team *enemyTeam);

        Team(const Team& other)=default;
        Team &operator=(const Team& other)=default;
        Team(Team&& other)=default;
        Team& operator=(Team &&other)=default;
    };
}
#endif