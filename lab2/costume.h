#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "actor.h"
using namespace std;

class Costume {
public:
    string description;
    shared_ptr<Actor> actor;

    Costume(const string& description, const shared_ptr<Actor>& actor);
    void showCostume();
};