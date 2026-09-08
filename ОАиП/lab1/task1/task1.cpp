#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x, y, z;

    //       Вариант 4
    //   x      y       z
    // 0.4e4 -0.875 -0.475e-3

    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    if (!cin) {
        cerr << "Error: Input error!\n";
        return 1;
    }

     double base = fabs(cos(x) - cos(y));
     double exponent = 1 + 2 * pow(sin(y), 2);

     if (base == 0 && exponent <= 0) {
        cerr << "Error: Math error!\n";
        return 2;
     }

     double part1 = pow(base, exponent);
     double part2 = 1 + z + pow(z, 2) / 2.0 + pow(z, 3) / 3.0 + pow(z, 4) / 4.0;

     double result = part1 * part2;

     cout << fixed << setprecision(4);
     cout << "Result = " << result << '\n';
     return 0;
 }