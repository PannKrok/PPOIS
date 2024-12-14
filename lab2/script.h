#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "play.h"
using namespace std;

class Script {
public:
    string content;
    shared_ptr<Play> play;

    Script(const string& content, const shared_ptr<Play>& play);
    void displayScript();
};