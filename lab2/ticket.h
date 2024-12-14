#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "play.h"
using namespace std;

class Ticket {
public:
    int ticketId;
    shared_ptr<Play> play;
    double price;

    Ticket(int id, const shared_ptr<Play>& play, double price);
    void showTicketInfo();
};