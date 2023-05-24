#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP
#include "Ninja.hpp"
using namespace std;
using namespace ariel;
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(std::string name , const Point &location);
        ~YoungNinja(){};
    };
#endif