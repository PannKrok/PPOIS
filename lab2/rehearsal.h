#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "play.h"
#include "actor.h"
using namespace std;

class Rehearsal {
public:
    shared_ptr<Play> play;
    vector<shared_ptr<Actor>> participants;

    Rehearsal(const shared_ptr<Play>& play);
    void addParticipant(const shared_ptr<Actor>& actor);
    void startRehearsal();
};