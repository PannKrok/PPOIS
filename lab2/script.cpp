#include "script.h"

Script::Script(const string& content, const shared_ptr<Play>& play)
    : content(content), play(play) {}

void Script::displayScript() {
    cout << "�������� ��� " << play->title << ": " << content << "\n";
}