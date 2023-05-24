#include "OldNinja.hpp"

OldNinja ::OldNinja(std::string name , const Point &location) :Ninja(std::move(name),location,150,8){}