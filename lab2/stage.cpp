#include "stage.h"

void Stage::addScene(const Scene& scene) {
    scenes.push_back(scene);
}

void Stage::showScenes() const {
    for (const auto& scene : scenes) {
        scene.displayScene();
    }
}