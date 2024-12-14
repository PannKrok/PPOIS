#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
using namespace std;

class Promotion {
public:
    std::string description;
    double discount; // in percentage

    Promotion(const std::string& description, double discount);
    void applyPromotion();
};