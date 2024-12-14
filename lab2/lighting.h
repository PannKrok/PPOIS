#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
using namespace std;

class Lighting {
public:
    string type;
    int intensity; // 1 to 10

    Lighting(const string& type, int intensity);
    void adjustLighting();
};