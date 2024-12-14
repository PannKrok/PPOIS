#include "actor.h"
#include "audience.h"
#include "costume.h"
#include "director.h"
#include "play.h"
#include "lighting.h"
#include "promotion.h"
#include "rehearsal.h"
#include "review.h"
#include "stage.h"
#include "script.h"
#include "scene.h"
#include "theater.h"
#include "ticket.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    // ������� �������
    auto actor1 = std::make_shared<Actor>("�������� ���������", 30, "�����");
    auto actor2 = std::make_shared<Actor>("�������� �������", 28, "���������");
    auto actor3 = std::make_shared<Actor>("��������� ��������", 35, "��������");

    // ������� �����
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    play->addActor(actor1);
    play->addActor(actor2);
    play->addActor(actor3);

    // ������� �����
    Theater theater("����������� ���������");
    theater.addPlay(play);

    // ������� ������
    auto ticket1 = std::make_shared<Ticket>(1, play, 50.0);
    auto ticket2 = std::make_shared<Ticket>(2, play, 50.0);

    // ������� ���������
    Audience audience1("���� �������� ");
    Audience audience2("���� ���������� ");
    audience1.buyTicket(ticket1);
    audience2.buyTicket(ticket2);

    // ��������
    Director director("�. ��������", 20);
    director.directPlay(play);

    // ������� �����
    Scene scene1("����� ������� ���������� ����� � ���������", play);
    Scene scene2("����� ��������� ����� �������� � ���������", play);

    // ������� �����
    Stage stage;
    stage.addScene(scene1);
    stage.addScene(scene2);

    // ������� �������
    Costume costume1("������ �����", actor1);
    Costume costume2("������ ���������", actor2);
    Costume costume3("������ ��������", actor3);

    // ���������� ���������� � ��������
    costume1.showCostume();
    costume2.showCostume();
    costume3.showCostume();

    // �������� �����
    stage.showScenes();

    // ���������
    Rehearsal rehearsal(play);
    rehearsal.addParticipant(actor1);
    rehearsal.addParticipant(actor2);
    rehearsal.addParticipant(actor3);
    rehearsal.startRehearsal();

    // �������� ������
    theater.showPlays();
    audience1.showTickets();
    audience2.showTickets();

    // ��������� �����
    Promotion promo("150 ��� ������������ ����������", 20);
    promo.applyPromotion();

    return 0;
}