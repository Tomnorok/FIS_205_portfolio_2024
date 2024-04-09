#include <iostream>
#include <cmath>
using namespace std;

double sqrt2(int precision, double start, double end) {
    double mid = (start + end) / 2;
    double square = mid * mid;
    if (end - start < pow(10, -precision))
        return mid;
    if (square > 2)
        return sqrt2(precision, start, mid);
    else
        return sqrt2(precision, mid, end);
}

int main() {
    int precision = 6;
    double result = sqrt2(precision, 1, 2);
    cout.precision(precision);
    cout << "Square root of 2 with 6 decimal digits precision: " << fixed << result << endl;
    return 0;
}
