#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ticket.h"
using namespace std; 

class Audience {
public:
    string name;
    vector<shared_ptr<Ticket>> tickets;

    Audience(const string& name);
    void buyTicket(const shared_ptr<Ticket>& ticket);
    void showTickets();
};