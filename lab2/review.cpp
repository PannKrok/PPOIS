#include "review.h"

Review::Review(const string& critic, const string& feedback, int rating)
    : critic(critic), feedback(feedback), rating(rating) {}

void Review::showReview() {
    cout << critic << " оценил эту пьессу на: " << rating << "/5. Рецензия: " << feedback << "\n";
}