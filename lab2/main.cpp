#include "actor.h"
#include "audience.h"
#include "costume.h"
#include "director.h"
#include "play.h"
#include "lighting.h"
#include "promotion.h"
#include "rehearsal.h"
#include "review.h"
#include "stage.h"
#include "script.h"
#include "scene.h"
#include "theater.h"
#include "ticket.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем актеров
    auto actor1 = std::make_shared<Actor>("Владимир Епифанцев", 30, "Ромео");
    auto actor2 = std::make_shared<Actor>("Светлана Баскова", 28, "Джульетта");
    auto actor3 = std::make_shared<Actor>("Станислав Барецкий", 35, "Меркуцио");

    // Создаем пьесу
    auto play = std::make_shared<Play>("Ромео и Джульетта", "Трагедия", 180);
    play->addActor(actor1);
    play->addActor(actor2);
    play->addActor(actor3);

    // Создаем театр
    Theater theater("Могилевский драмтеатр");
    theater.addPlay(play);

    // Создаем билеты
    auto ticket1 = std::make_shared<Ticket>(1, play, 50.0);
    auto ticket2 = std::make_shared<Ticket>(2, play, 50.0);

    // Создаем аудиторию
    Audience audience1("Иван Васильев ");
    Audience audience2("Иван Шелковский ");
    audience1.buyTicket(ticket1);
    audience2.buyTicket(ticket2);

    // Директор
    Director director("У. Шейкспир", 20);
    director.directPlay(play);

    // Создаем сцену
    Scene scene1("Сцена первого знакомства Ромео и Джульетты", play);
    Scene scene2("Сцена конфликта между Меркуцио и Тибальтом", play);

    // Создаем сцену
    Stage stage;
    stage.addScene(scene1);
    stage.addScene(scene2);

    // Создаем костюмы
    Costume costume1("костюм Ромео", actor1);
    Costume costume2("костюм Джульетты", actor2);
    Costume costume3("костюм Меркуцио", actor3);

    // Показываем информацию о костюмах
    costume1.showCostume();
    costume2.showCostume();
    costume3.showCostume();

    // Показать сцены
    stage.showScenes();

    // Репетиция
    Rehearsal rehearsal(play);
    rehearsal.addParticipant(actor1);
    rehearsal.addParticipant(actor2);
    rehearsal.addParticipant(actor3);
    rehearsal.startRehearsal();

    // Показать детали
    theater.showPlays();
    audience1.showTickets();
    audience2.showTickets();

    // Применить акцию
    Promotion promo("150 лет Могилевскому драмтеатру", 20);
    promo.applyPromotion();

    return 0;
}