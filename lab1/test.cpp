#include "pch.h"
#include "C:\Users\Pan Krok\source\repos\lab1\lab1\turingmachin.h"
#include "gtest/gtest.h"
#include "C:\Users\Pan Krok\source\repos\lab1\lab1\turingmachin.cpp"

class TuringMachineTest : public ::testing::Test {
protected:
    Turing_Machine tm;

    void SetUp() override {
        tm.Set_Pool("01"); 
        tm.Set_Condit(2);  
    }
};

TEST_F(TuringMachineTest, TestCheckInput) {
    EXPECT_TRUE(tm.Check_Input('0'));
    EXPECT_TRUE(tm.Check_Input('1'));
    EXPECT_FALSE(tm.Check_Input('2'));
}

TEST_F(TuringMachineTest, TestSetTapeValid) {
    EXPECT_TRUE(tm.Set_Tape("0101"));
    tm.Show_Tape(); 
}

TEST_F(TuringMachineTest, TestSetTapeInvalid) {
    EXPECT_FALSE(tm.Set_Tape("0123")); 
}

TEST_F(TuringMachineTest, TestCheckTermValid) {
    EXPECT_TRUE(tm.Set_Term("0 N q1"));
    EXPECT_TRUE(tm.Set_Term("1 R q0"));
}

TEST_F(TuringMachineTest, TestCheckTermInvalid) {
    EXPECT_FALSE(tm.Set_Term("2 N q1")); 
    EXPECT_FALSE(tm.Set_Term("0 X q1")); 
}

TEST_F(TuringMachineTest, TestChangeTapeInvalid) {
    EXPECT_FALSE(tm.Change_Tape(0, '2')); 
}


TEST_F(TuringMachineTest, TestChangeTermInvalid) {
    tm.Set_Term("0 N q1");
    tm.Push_Back();
    EXPECT_FALSE(tm.Change_Term(0, '2', "1 R q0"));
}

TEST_F(TuringMachineTest, TestSetTermEmpty) {
    EXPECT_FALSE(tm.Set_Term("")); 
}

TEST_F(TuringMachineTest, TestChangeTermValid) {
    tm.Set_Term("0 N q1");
    tm.Push_Back();
    EXPECT_TRUE(tm.Change_Term(0, '0', "1 R q0")); 
}

TEST_F(TuringMachineTest, TestCheckFinWithNoEnd) {
    EXPECT_FALSE(tm.Check_Fin());
}



TEST_F(TuringMachineTest, TestInvalidInputDuringExecution) {
    tm.Set_Tape("01");
    tm.Set_Term("0 R q1");
    tm.Set_Term("1 N !");
    tm.Push_Back();
    EXPECT_FALSE(tm.Change_Tape(0, '2')); 
}

TEST_F(TuringMachineTest, TestCheckInput_ValidChar) {
    EXPECT_TRUE(tm.Check_Input('0'));
    EXPECT_TRUE(tm.Check_Input('1'));
}

TEST_F(TuringMachineTest, TestCheckInput_InvalidChar) {
    EXPECT_FALSE(tm.Check_Input('2'));
    EXPECT_FALSE(tm.Check_Input('x'));
}

TEST_F(TuringMachineTest, TestSetTape_ValidInput) {
    EXPECT_TRUE(tm.Set_Tape("101"));
    tm.Show_Tape();
}

TEST_F(TuringMachineTest, TestSetTape_InvalidInput) {
    EXPECT_FALSE(tm.Set_Tape("102"));
}

TEST_F(TuringMachineTest, TestCheckTerm_ValidTerm) {
    EXPECT_TRUE(tm.Set_Term("0 N q1"));
    EXPECT_TRUE(tm.Set_Term("1 R q0"));
}

TEST_F(TuringMachineTest, TestCheckTerm_InvalidTerm) {
    EXPECT_FALSE(tm.Set_Term("2 N q1"));
}

TEST_F(TuringMachineTest, TestChangeTape_InvalidChange) {
    EXPECT_FALSE(tm.Change_Tape(1, '2')); 
}

TEST_F(TuringMachineTest, TestChangeTerm_InvalidChange) {
    EXPECT_FALSE(tm.Change_Term(2, '0', "0 N q0")); 
}

TEST(MainFunctionTest, TestMain) {
    int argc = 0;
    char** argv = nullptr;
    ::testing::InitGoogleTest(&argc, argv);
}



TEST_F(TuringMachineTest, TestPushBack) {
    tm.Set_Term("0 R q1"); 
    tm.Set_Term("1 N q0"); 
    tm.Push_Back();
    testing::internal::CaptureStdout();
    tm.Show_Terms();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("0 R q1"), std::string::npos); 
    EXPECT_NE(output.find("1 N q0"), std::string::npos); 
}

TEST_F(TuringMachineTest, CheckFinNotFinished) {
    tm.Set_Tape("010"); 
    EXPECT_FALSE(tm.Check_Fin()); 
}

TEST_F(TuringMachineTest, TestShowTape) {
    tm.Set_Tape("010"); 
    testing::internal::CaptureStdout();
    tm.Show_Tape(); 
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("010"), std::string::npos); 
}


TEST_F(TuringMachineTest, ChangeConditUpdatesCurrentCondition) {
    int new_condition = 1;
    tm.Change_Condit(new_condition);
    EXPECT_EQ(tm.curr_condit, new_condition);
}



TEST_F(TuringMachineTest, ChangeConditUpdatesConditionMultipleTimes) {
    int first_condition = 2;
    int second_condition = 3;
    tm.Change_Condit(first_condition);
    tm.Change_Condit(second_condition);
    EXPECT_EQ(tm.curr_condit, second_condition); 
}

TEST_F(TuringMachineTest, CheckTermReturnsFalseForInvalidTerm) {
    string invalid_term = "invalid";
    bool result = tm.Check_Term(invalid_term);
    EXPECT_FALSE(result) << "Check_Term should return false for an invalid term.";
}

TEST_F(TuringMachineTest, CheckTermReturnsFalseForMultipleInvalidTerms) {
    vector<string> invalid_terms = { "invalid1", "invalid2", "invalid3" };
    for (const auto& term : invalid_terms) {
        EXPECT_FALSE(tm.Check_Term(term)) << "Check_Term should return false for " << term;
    }
}

TEST_F(TuringMachineTest, TestShowTerms) {
    tm.Set_Term("0 R q1"); 
    tm.Set_Term("1 N q0"); 
    tm.Push_Back();        

    testing::internal::CaptureStdout();
    tm.Show_Terms();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("0 R q1"), std::string::npos); 
    EXPECT_NE(output.find("1 N q0"), std::string::npos); 
}

TEST_F(TuringMachineTest, CheckInputValid) {
    EXPECT_TRUE(tm.Check_Input('0'));
    EXPECT_TRUE(tm.Check_Input('1'));
    EXPECT_FALSE(tm.Check_Input('2'));
}

TEST_F(TuringMachineTest, ChangeTapeInvalidInput) {
    EXPECT_FALSE(tm.Change_Tape(1, '2'));
}

TEST_F(TuringMachineTest, CheckFinTest) {
    EXPECT_FALSE(tm.Check_Fin());
}

TEST_F(TuringMachineTest, ChangeTermInvalid) {
    EXPECT_FALSE(tm.Change_Term(2, '0', "0 R q1"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

