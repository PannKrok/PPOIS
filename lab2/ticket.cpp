#include "ticket.h"

Ticket::Ticket(int id, const shared_ptr<Play>& play, double price)
    : ticketId(id), play(play), price(price) {}

void Ticket::showTicketInfo() {
    cout << "����� ������: " << ticketId << ", ������: " << play->title << ", ����: " << price << " ���. ���" << "\n";
}