#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "play.h"
using namespace std;

class Theater {
public:
    string name;
    vector<shared_ptr<Play>> plays;

    Theater(const string& name);
    void addPlay(const shared_ptr<Play>& play);
    void showPlays();
};