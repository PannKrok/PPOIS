#include "turingmachin.h"
#include <iostream>

bool Turing_Machine::Check_Input(char write) {
	for (char i : pool)
		if (i == write)
			return true;
	return false;
}

bool Turing_Machine::Change_Tape(int num, char write) {
	if (!Check_Input(write))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	tape[num] = write;
	return true;
}

bool Turing_Machine::Change_Term(int num, char c, string rule) {
	int i;
	if ((num < 0) || (num >= condit))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	if (!Check_Input(c))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	if (!Check_Term(rule))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	for (i = 0; pool[i] != c;)
		i++;
	terms[num][i] = rule;
	cout << endl;
	return true;
}


bool Turing_Machine::Check_Term(string term) {
	if ((term.size() < 5) || (term.size() > 6))
		return false;
	if (!Check_Input(term[0]))
		return false;
	if ((term[2] != 'N') && (term[2] != 'R') && (term[2] != 'L'))
		return false;
	if ((((term[4] != 'q') && ((static_cast<int>(term[5]) - 48) > condit)) || (term[4] != 'q') || ((static_cast<int>(term[5]) - 48) >= condit)) && (term[4] != '!'))
		return false;
	if ((term[1] != ' ') || (term[3] != ' ') || ((term[1] != ' ') && (term[3] != ' ')))
		return false;
	if (term.length() > 6)
		return false;
	if ((term[4] == 'q') && (term[term.length() - 1] == 'q') || ((term[4] == '!') && (term[term.length() - 1] != '!')))
		return false;
	if ((term[term.length() - 1] == '!') && (term[term.length() - 2] == '!'))
		return false;
	return true;
}

string Turing_Machine::Find_Term(vector<vector<string>> terms, int curr_condit, char write) {
	for (int i = 0; i < pool.size(); i++)
		if (write == pool[i])
			return terms[curr_condit][i];
}

void Turing_Machine::Left() {
	if (curr == 1)
		tape = "~" + tape;
	curr--;
}

void Turing_Machine::Right() {
	if (curr == tape.length() - 2)
		tape = tape + "~";
	curr++;
}

void Turing_Machine::Write(char i) {
	tape[curr] = i;
}

void Turing_Machine::Change_Condit(int num) {
	curr_condit = num;
}

void Turing_Machine::Set_Condit(int condit) {
	this->condit = condit;
}

void Turing_Machine::Set_Pool(string tape) {
	this->pool = tape + '~';
}

bool Turing_Machine::Set_Tape(string tape) {
	for (char i : tape)
		if (!Check_Input(i))
		{
			cout << "Неправильный ввод";
			return false;
		}
	this->tape = "~" + tape + "~";
	return true;
}

bool Turing_Machine::Check_Fin() {
	for (int i = 0; i < terms.size(); i++)
		for (int j = 0; j < terms[i].size(); j++)
			for (char s : terms[i][j])
				if (s == '!')
					return true;
	std::cout << "Не предусмотрен конец алгоритма" << std::endl;
	terms_condit.clear();
	terms.clear();
	return false;
}

bool Turing_Machine::Set_Term(string rule) {
	if (!Check_Term(rule))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	terms_condit.push_back(rule);
	return true;
}

void Turing_Machine::Push_Back() {
	terms.push_back(terms_condit);
	terms_condit.clear();
}

void Turing_Machine::Show_Terms() {
	cout << "        ";
	for (char i : pool)
		cout << i << "         ";
	cout << endl;
	for (int i = 0; i < terms.size(); i++)
	{
		cout << "q" << i << "    ";
		for (string j : terms[i])
			cout << j << "    ";
		cout << endl;
	}
	cout << endl;
}

void Turing_Machine::Show_Tape() {
	cout << "Слово на ленте: " << tape << endl;
}

void Turing_Machine::Execute(char c) {
	string term;
	int i;
	curr_condit = 0;
	curr = 1;
	while (true)
	{
		term = Find_Term(terms, curr_condit, tape[curr]);
		for (i = 0; i < term.size(); i++)
		{
			switch (term[i])
			{
			case 'R':
				Right();
				break;
			case 'L':
				Left();
				break;
			case 'N':
				break;
			case '!':
				break;
			case 'q':
				Change_Condit(static_cast<int>(term[i + 1]) - 48);
				i++;
				break;
			case ' ':
				break;
			default:
				Write(term[i]);
				break;
			}
		}
		if (term[i - 1] == '!')
			break;
		if (c == 'Y')
		{
			Show_Tape();
			Show_Terms();
		}
	}
	cout << endl;
}