#include "scene.h"

Scene::Scene(const string& description, const shared_ptr<Play>& play)
    : description(description), play(play) {}

void Scene::displayScene() const {
    cout << "—цена: " << description << " из " << play->title << ".\n";
}
