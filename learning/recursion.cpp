
#include <iostream>

using namespace std;

long factorial (long x) {
    if (x<=1) return 1;
    return (x * factorial(x-1));
}

int main() {
    long number = 4;
    cout << number << "!" << " = " << factorial(number);
    return 0;
}
