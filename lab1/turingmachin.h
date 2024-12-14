#pragma once
#include <vector>
#include <string>
using namespace std;

class Turing_Machine
{
private:
    int curr;
    int condit;
    string tape;
    string pool;
    vector<string> terms_condit;
    vector<vector<string>> terms;
    string Find_Term(vector<vector<string>> terms, int curr_condit, char symbol);
    void Left();
    void Right();
    void Write(char i);
    
public:
    int curr_condit;
    bool Check_Term(string term);
    void Change_Condit(int num);
    bool Check_Input(char write);
    bool Check_Fin();
    void Set_Condit(int condit);
    bool Set_Tape(string tape);
    void Show_Terms();
    void Push_Back();
    bool Set_Term(string term);
    bool Change_Tape(int num, char write);
    void Execute(char c);
    bool Change_Term(int num, char c, string term);
    void Show_Tape();
    void Set_Pool(string pool);     
};