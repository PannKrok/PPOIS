#include "play.h"


Play::Play(const string& title, const string& genre, int duration)
    : title(title), genre(genre), duration(duration) {}

void Play::addActor(const shared_ptr<Actor>& actor) {
    actors.push_back(actor);
}
void Play::showDetails() {
    cout << "Пьесса: " << title << ", Жанр: " << genre << ", Продолжительность: " << duration << " минут\n";
}