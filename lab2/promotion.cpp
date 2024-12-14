#include "promotion.h"

Promotion::Promotion(const string& description, double discount)
    : description(description), discount(discount) {}

void Promotion::applyPromotion() {
    cout << "Праздник: " << description << " со скидкой " << discount << "%.\n";
}