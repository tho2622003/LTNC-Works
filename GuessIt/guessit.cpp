#include <iostream>
#include <cstdlib>
using namespace std;

int random() {
    int a = rand() % (100 - 1 + 1) + 1;
    return a;
}

int play() {
    int b;
    cout << "guess a number (1 to 100): ";
    cin >> b;
    return b;
}

void answer(int a, int b) {
    if (a > b) {
        cout << "too small" << endl;
    }
    else if (a < b) {
        cout << "too big" << endl;
    }
    else cout << "congratulations";
}

int main() {
    int secret = random();
    int guess;
    do {
        guess = play();
        answer(secret, guess);
    } while (guess != secret);
}
