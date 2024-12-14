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
    Actor actor("Владимир Епифанцев", 30, "Ромео");
    EXPECT_EQ(actor.name, "Владимир Епифанцев");
    EXPECT_EQ(actor.age, 30);
    EXPECT_EQ(actor.role, "Ромео");
}

TEST(ActorTest, Perform) {
    Actor actor("Владимир Епифанцев", 30, "Ромео");
    testing::internal::CaptureStdout();
    actor.perform();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Владимир Епифанцев играет как Ромео.\n");
}

// Test for Play class
TEST(PlayTest, Initialization) {
    Play play("Ромео и Джульетта", "Трагедия", 180);
    EXPECT_EQ(play.title, "Ромео и Джульетта");
    EXPECT_EQ(play.genre, "Трагедия");
    EXPECT_EQ(play.duration, 180);
}

TEST(PlayTest, ShowDetails) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    testing::internal::CaptureStdout();
    play->showDetails();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Пьесса: Ромео и Джульетта, Жанр: Трагедия, Продолжительность: 180 минут\n");
}

// Test for Theater class
TEST(TheaterTest, Initialization) {
    Theater theater("Могилевский драмтеатр");
    EXPECT_EQ(theater.name, "Могилевский драмтеатр");
}

TEST(TheaterTest, AddPlay) {
    Theater theater("Могилевский драмтеатр");
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    theater.addPlay(play);
    EXPECT_EQ(theater.plays.size(), 1);
}

TEST(TheaterTest, ShowPlays) {
    Theater theater("Могилевский драмтеатр");
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    theater.addPlay(play);
    testing::internal::CaptureStdout();
    theater.showPlays();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Играет в Могилевский драмтеатр:\nПьесса: Ромео и Джульетта, Жанр: Трагедия, Продолжительность: 180 минут\n");
}

// Test for Ticket class
TEST(TicketTest, Initialization) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    Ticket ticket(1, play, 50.0);
    EXPECT_EQ(ticket.ticketId, 1);
    EXPECT_EQ(ticket.price, 50.0);
}

TEST(TicketTest, ShowTicketInfo) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    Ticket ticket(1, play, 50.0);
    testing::internal::CaptureStdout();
    ticket.showTicketInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Номер билета: 1, Пьесса: Ромео и Джульетта, Цена: 50 бел. руб\n");
}

// Test for Audience class
TEST(AudienceTest, Initialization) {
    Audience audience("Иван Васильев ");
    EXPECT_EQ(audience.name, "Иван Васильев ");
}

TEST(AudienceTest, BuyTicket) {
    Audience audience("Иван Васильев");
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    auto ticket = std::make_shared<Ticket>(1, play, 50.0);
    audience.buyTicket(ticket);
    EXPECT_EQ(audience.tickets.size(), 1);
}

TEST(AudienceTest, ShowTickets) {
    Audience audience("Иван Васильев ");
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    auto ticket = std::make_shared<Ticket>(1, play, 50.0);
    audience.buyTicket(ticket);
    testing::internal::CaptureStdout();
    audience.showTickets();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Иван Васильев приобрел билет\nНомер билета: 1, Пьесса: Ромео и Джульетта, Цена: 50 бел. руб\n");
}

// Test for Director class
TEST(DirectorTest, Initialization) {
    Director director("У. Шейкспир", 20);
    EXPECT_EQ(director.name, "У. Шейкспир");
    EXPECT_EQ(director.experienceYears, 20);
}

TEST(DirectorTest, DirectPlay) {
    Director director("У. Шейкспир", 20);
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    testing::internal::CaptureStdout();
    director.directPlay(play);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "У. Шейкспир автор Ромео и Джульетта.\n");
}

// Test for Scene class
TEST(SceneTest, Initialization) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    Scene scene("Сцена первого знакомства", play);
    EXPECT_EQ(scene.description, "Сцена первого знакомства");
}

TEST(SceneTest, DisplayScene) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    Scene scene("Сцена первого знакомства", play);
    testing::internal::CaptureStdout();
    scene.displayScene();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Сцена: Сцена первого знакомства из Ромео и Джульетта.\n");
}

// Test for Promotion class
TEST(PromotionTest, Initialization) {
    Promotion promo("150 лет Могилевскому драмтеатру", 20);
    EXPECT_EQ(promo.description, "150 лет Могилевскому драмтеатру");
    EXPECT_EQ(promo.discount, 20);
}

TEST(PromotionTest, ApplyPromotion) {
    Promotion promo("150 лет Могилевскому драмтеатру", 20);
    testing::internal::CaptureStdout();
    promo.applyPromotion();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Праздник: 150 лет Могилевскому драмтеатру со скидкой 20%.\n");
}


/*
TEST(BoxOfficeTest, SellTicket) {
    BoxOffice boxOffice;
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    auto ticket = std::make_shared<Ticket>(1, play, 50.0);
    testing::internal::CaptureStdout();
    boxOffice.sellTicket(ticket);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Номер билета: 1.\n");
}
*/
// Test for Script class
TEST(ScriptTest, Initialization) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    Script script("Содержимое сценария", play);
    EXPECT_EQ(script.content, "Содержимое сценария");
}

TEST(ScriptTest, DisplayScript) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    Script script("Содержимое сценария", play);
    testing::internal::CaptureStdout();
    script.displayScript();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Сценарий для Ромео и Джульетта: Содержимое сценария\n");
}

TEST(RehearsalTest, Initialization) {
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    Rehearsal rehearsal(play);
    EXPECT_EQ(rehearsal.play, play);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}