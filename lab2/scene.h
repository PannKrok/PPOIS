#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "play.h"
using namespace std;

class Scene {
public:
    string description;
    shared_ptr<Play> play;

    Scene(const string& description, const shared_ptr<Play>& play);
    void displayScene() const;
};