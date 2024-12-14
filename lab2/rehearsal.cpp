#include "rehearsal.h"

Rehearsal::Rehearsal(const shared_ptr<Play>& play) : play(play) {}

void Rehearsal::addParticipant(const shared_ptr<Actor>& actor) {
    participants.push_back(actor);
}
void Rehearsal::startRehearsal() {
    cout << "Репетиция для " << play->title << " с актерами:\n";
    for (const auto& actor : participants) {
        cout << "- " << actor->name << "\n";
    }
}