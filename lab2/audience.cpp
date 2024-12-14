#include "audience.h"

Audience::Audience(const string& name) : name(name) {}

void Audience::buyTicket(const shared_ptr<Ticket>& ticket) {
    tickets.push_back(ticket);
}

void Audience::showTickets() {
    cout << name << "приобрел билет\n";
    for (const auto& ticket : tickets) {
        ticket->showTicketInfo();
    }
}