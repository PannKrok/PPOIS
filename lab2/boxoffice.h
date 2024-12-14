#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ticket.h"

class BoxOffice {
public:
    // ����� ��� ������� ������
    void sellTicket(const std::shared_ptr<Ticket>& ticket);

    // ����� ��� ����������� ��������� �������
    void showSoldTickets() const;

private:
    map<int, std::shared_ptr<Ticket>> tickets; // ������ ��������� ������, ���� - ID ������
};