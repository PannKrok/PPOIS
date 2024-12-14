#include "director.h"

Director::Director(const string& name, int experience) : name(name), experienceYears(experience) {}

void Director::directPlay(const shared_ptr<Play>& play) {
    cout << name << " автор " << play->title << ".\n";
}