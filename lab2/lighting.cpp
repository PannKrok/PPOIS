#include "lighting.h"

Lighting::Lighting(const string& type, int intensity) : type(type), intensity(intensity) {}

void Lighting::adjustLighting() {
    cout << "��������� " << type << " ��������� �  " << intensity << ".\n";
}
