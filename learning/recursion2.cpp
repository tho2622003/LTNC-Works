#include <iostream>

long long fibonacci (long x) {
    if (x<=1) return 1;
    return (fibonacci(x-1) + fibonacci(x-2));
}

int main() {
    long number = 59;
    std::cout << "fibonacci(" << number << ") = " << fibonacci(number);
    return 0;
}
