#include <iostream>


double calculateSimpleInterest(double principal, double time, double rate = 15.0) {
    return (principal * rate * time) / 100.0;
}

int main() {
    double principal, time;
    std::cout << "Enter the principal amount: ";
    std::cin >> principal;
    std::cout << "Enter the time (in years): ";
    std::cin >> time;

 
    double interest = calculateSimpleInterest(principal, time);

    std::cout << "Simple Interest: $" << interest << std::endl;

    return 0;
}

