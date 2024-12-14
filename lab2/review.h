#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
using namespace std;

class Review {
public:
    string critic;
    string feedback;
    int rating; // 1 to 5

    Review(const string& critic, const string& feedback, int rating);
    void showReview();
};