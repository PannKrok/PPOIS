#include "review.h"

Review::Review(const string& critic, const string& feedback, int rating)
    : critic(critic), feedback(feedback), rating(rating) {}

void Review::showReview() {
    cout << critic << " ������ ��� ������ ��: " << rating << "/5. ��������: " << feedback << "\n";
}