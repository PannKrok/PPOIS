#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "play.h"
using namespace std;


class Director {
public:
    string name;
    int experienceYears;

    Director(const string& name, int experience);
    void directPlay(const shared_ptr<Play>& play);
};