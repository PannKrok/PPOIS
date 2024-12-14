#include "costume.h"

Costume::Costume(const string& description, const shared_ptr<Actor>& actor)
    : description(description), actor(actor) {}

void Costume::showCostume() {
    cout << actor->name << " одет в " << description << ".\n";
}