#include "theater.h"

Theater::Theater(const string& name) : name(name) {}

void Theater::addPlay(const shared_ptr<Play>& play) {
    plays.push_back(play);
}

void Theater::showPlays() {
    cout << "»грает в " << name << ":\n";
    for (const auto& play : plays) {
        play->showDetails();
    }
}
