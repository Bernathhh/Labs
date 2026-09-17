#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    //       Вариант 4
    //   x      y       z
    // 0.4e4 -0.875 -0.475e-3
    
    double x = 0.0, y = 0.0, z = 0.0;

    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    if (!cin) {
        cerr << "Error: Input error!\n";
        return 1;
    }

    double base = fabs(cos(x) - cos(y));
    double exponent = 1.0 + 2.0 * pow(sin(y), 2);

    if (base == 0.0 && exponent <= 0.0) {
        cerr << "Error: Math error!\n";
        return 2;
    }

    double part1 = pow(base, exponent);

    double z2 = z * z;
    double z3 = z2 * z;
    double z4 = z3 * z;
    double part2 = 1.0 + z + (z2 / 2.0) + (z3 / 3.0) + (z4 / 4.0);

    double result = part1 * part2;

    cout << fixed << setprecision(4);
    cout << "Result = " << result << '\n';

    return 0;
}