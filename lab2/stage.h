#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "scene.h"
using namespace std;

class Stage {
public:
    vector<Scene> scenes;

    void addScene(const Scene& scene);
    void showScenes() const;
};