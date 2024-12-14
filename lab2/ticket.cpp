#include "ticket.h"

Ticket::Ticket(int id, const shared_ptr<Play>& play, double price)
    : ticketId(id), play(play), price(price) {}

void Ticket::showTicketInfo() {
    cout << "Номер билета: " << ticketId << ", Пьесса: " << play->title << ", Цена: " << price << " бел. руб" << "\n";
}