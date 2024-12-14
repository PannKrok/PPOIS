#include "boxoffice.h"

void BoxOffice::sellTicket(const std::shared_ptr<Ticket>& ticket) {
    // Добавляет билет в коллекцию, используя его ID в качестве ключа
    tickets[ticket->ticketId] = ticket;
    std::cout << "Sold ticket ID: " << ticket->ticketId << ".\n";
}

void BoxOffice::showSoldTickets() const {
    if (tickets.empty()) {
        std::cout << "No tickets sold yet.\n";
        return;
    }

    std::cout << "Sold Tickets:\n";
    for (const auto& pair : tickets) {
        pair.second->showTicketInfo(); // Выводим информацию о каждом проданном билете
    }
}