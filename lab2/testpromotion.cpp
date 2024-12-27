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

