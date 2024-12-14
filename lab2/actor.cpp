#include "actor.h"

Actor::Actor(const string& name, int age, const string& role)
    : name(name), age(age), role(role) {}

void Actor::perform() {
    cout << name << " играет как " << role << ".\n";
}

