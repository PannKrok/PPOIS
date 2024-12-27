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


