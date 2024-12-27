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

