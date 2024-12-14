#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ticket.h"

class BoxOffice {
public:
    // Метод для продажи билета
    void sellTicket(const std::shared_ptr<Ticket>& ticket);

    // Метод для отображения проданных билетов
    void showSoldTickets() const;

private:
    map<int, std::shared_ptr<Ticket>> tickets; // Хранит проданные билеты, ключ - ID билета
};