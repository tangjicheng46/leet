#include <iostream>

double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    
    if (n < 0) {
        if (n == INT_MIN) {
            return 1.0 / (x * myPow(x, -(n + 1)));
        } else {
            n = -n;
            x = 1.0 / x;
        }
    }
    
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    
    return result;
}

int main() {
    double x = 2.0;
    int n = 10;
    double result = myPow(x, n);
    std::cout << x << " raised to the power " << n << " is: " << result << std::endl;
    return 0;
}
