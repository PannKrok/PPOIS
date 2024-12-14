#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "actor.h"
using namespace std;

class Play {
public:
    string title;
    string genre;
    int duration; // in minutes
    vector<shared_ptr<Actor>> actors;

    Play(const string& title, const std::string& genre, int duration);
    void addActor(const shared_ptr<Actor>& actor);
    void showDetails();
};