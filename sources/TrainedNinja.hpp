#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP
#include "Ninja.hpp"
using namespace std;
using namespace ariel;
#include "Ninja.hpp"
class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(std::string name , const Point &location);
        ~TrainedNinja(){};
    };
#endif