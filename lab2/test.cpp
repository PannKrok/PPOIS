#include "pch.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\actor.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\audience.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\costume.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\director.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\lighting.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\play.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\promotion.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\rehearsal.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\review.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\scene.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\script.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\stage.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\theater.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\ticket.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\boxoffice.h"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\actor.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\audience.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\boxoffice.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\costume.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\director.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\lighting.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\play.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\promotion.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\review.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\rehearsal.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\scene.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\script.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\stage.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\theater.cpp"
#include "C:\Users\Pan Krok\source\repos\ppois2\ppois2\ticket.cpp"
#include <gtest/gtest.h>

// Test for Actor class
TEST(ActorTest, Initialization) {
    Actor actor("�������� ���������", 30, "�����");
    EXPECT_EQ(actor.name, "�������� ���������");
    EXPECT_EQ(actor.age, 30);
    EXPECT_EQ(actor.role, "�����");
}

TEST(ActorTest, Perform) {
    Actor actor("�������� ���������", 30, "�����");
    testing::internal::CaptureStdout();
    actor.perform();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "�������� ��������� ������ ��� �����.\n");
}

// Test for Play class
TEST(PlayTest, Initialization) {
    Play play("����� � ���������", "��������", 180);
    EXPECT_EQ(play.title, "����� � ���������");
    EXPECT_EQ(play.genre, "��������");
    EXPECT_EQ(play.duration, 180);
}

TEST(PlayTest, ShowDetails) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    testing::internal::CaptureStdout();
    play->showDetails();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "������: ����� � ���������, ����: ��������, �����������������: 180 �����\n");
}

// Test for Theater class
TEST(TheaterTest, Initialization) {
    Theater theater("����������� ���������");
    EXPECT_EQ(theater.name, "����������� ���������");
}

TEST(TheaterTest, AddPlay) {
    Theater theater("����������� ���������");
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    theater.addPlay(play);
    EXPECT_EQ(theater.plays.size(), 1);
}

TEST(TheaterTest, ShowPlays) {
    Theater theater("����������� ���������");
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    theater.addPlay(play);
    testing::internal::CaptureStdout();
    theater.showPlays();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "������ � ����������� ���������:\n������: ����� � ���������, ����: ��������, �����������������: 180 �����\n");
}

// Test for Ticket class
TEST(TicketTest, Initialization) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    Ticket ticket(1, play, 50.0);
    EXPECT_EQ(ticket.ticketId, 1);
    EXPECT_EQ(ticket.price, 50.0);
}

TEST(TicketTest, ShowTicketInfo) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    Ticket ticket(1, play, 50.0);
    testing::internal::CaptureStdout();
    ticket.showTicketInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "����� ������: 1, ������: ����� � ���������, ����: 50 ���. ���\n");
}

// Test for Audience class
TEST(AudienceTest, Initialization) {
    Audience audience("���� �������� ");
    EXPECT_EQ(audience.name, "���� �������� ");
}

TEST(AudienceTest, BuyTicket) {
    Audience audience("���� ��������");
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    auto ticket = std::make_shared<Ticket>(1, play, 50.0);
    audience.buyTicket(ticket);
    EXPECT_EQ(audience.tickets.size(), 1);
}

TEST(AudienceTest, ShowTickets) {
    Audience audience("���� �������� ");
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    auto ticket = std::make_shared<Ticket>(1, play, 50.0);
    audience.buyTicket(ticket);
    testing::internal::CaptureStdout();
    audience.showTickets();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "���� �������� �������� �����\n����� ������: 1, ������: ����� � ���������, ����: 50 ���. ���\n");
}

// Test for Director class
TEST(DirectorTest, Initialization) {
    Director director("�. ��������", 20);
    EXPECT_EQ(director.name, "�. ��������");
    EXPECT_EQ(director.experienceYears, 20);
}

TEST(DirectorTest, DirectPlay) {
    Director director("�. ��������", 20);
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    testing::internal::CaptureStdout();
    director.directPlay(play);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "�. �������� ����� ����� � ���������.\n");
}

// Test for Scene class
TEST(SceneTest, Initialization) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    Scene scene("����� ������� ����������", play);
    EXPECT_EQ(scene.description, "����� ������� ����������");
}

TEST(SceneTest, DisplayScene) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    Scene scene("����� ������� ����������", play);
    testing::internal::CaptureStdout();
    scene.displayScene();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "�����: ����� ������� ���������� �� ����� � ���������.\n");
}

// Test for Promotion class
TEST(PromotionTest, Initialization) {
    Promotion promo("150 ��� ������������ ����������", 20);
    EXPECT_EQ(promo.description, "150 ��� ������������ ����������");
    EXPECT_EQ(promo.discount, 20);
}

TEST(PromotionTest, ApplyPromotion) {
    Promotion promo("150 ��� ������������ ����������", 20);
    testing::internal::CaptureStdout();
    promo.applyPromotion();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "��������: 150 ��� ������������ ���������� �� ������� 20%.\n");
}


/*
TEST(BoxOfficeTest, SellTicket) {
    BoxOffice boxOffice;
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    auto ticket = std::make_shared<Ticket>(1, play, 50.0);
    testing::internal::CaptureStdout();
    boxOffice.sellTicket(ticket);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "����� ������: 1.\n");
}
*/
// Test for Script class
TEST(ScriptTest, Initialization) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    Script script("���������� ��������", play);
    EXPECT_EQ(script.content, "���������� ��������");
}

TEST(ScriptTest, DisplayScript) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    Script script("���������� ��������", play);
    testing::internal::CaptureStdout();
    script.displayScript();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "�������� ��� ����� � ���������: ���������� ��������\n");
}

TEST(RehearsalTest, Initialization) {
    auto play = std::make_shared<Play>("����� � ���������", "��������", 180);
    Rehearsal rehearsal(play);
    EXPECT_EQ(rehearsal.play, play);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}