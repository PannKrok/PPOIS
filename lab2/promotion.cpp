#include "promotion.h"

Promotion::Promotion(const string& description, double discount)
    : description(description), discount(discount) {}

void Promotion::applyPromotion() {
    cout << "��������: " << description << " �� ������� " << discount << "%.\n";
}