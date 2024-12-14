#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
using namespace std;

class Actor {
public:
    string name;
    int age;
    string role;

    Actor(const string& name, int age, const string& role);
    void perform();
};






















