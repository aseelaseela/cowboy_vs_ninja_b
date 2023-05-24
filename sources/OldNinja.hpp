#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP
#include "Ninja.hpp"
using namespace std;
using namespace ariel;
class OldNinja : public Ninja
    {
    public:
        OldNinja(std::string name , const Point &location);
        ~OldNinja(){};
    };

#endif