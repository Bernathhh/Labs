#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    //       Вариант 4
    // function 1: 1 1 0.5 1
    // function 2: 1 1 1 2
    // function 3: 1 1 5 3

    double a = 0.0, b = 0.0, z = 0.0;
    int choice = 0;

    cout << "Enter a, b, z and function choice (1: 2*x, 2: x^2, 3: x/3): ";
    cin >> a >> b >> z >> choice;

    if (!cin or choice < 1 or choice > 3) {
        cerr << "Error: Invalid input data!\n";
        return 1;
    }

    // Определение x в зависимости от z
    double x = 0.0;
    if (z < 1.0) {
        x = z * z * z + 0.2;
        cout << "Condition: z < 1 (x = z^3 + 0.2)\n";
    } else {
        x = z + log(z);
        cout << "Condition: z >= 1 (x = z + ln(z))\n";
    }

    // Вычисление функции phi(x) по номеру choice
    double phi = 0.0;
    switch (choice) {
        case 1:
            phi = 2.0 * x;
            cout << "Function: phi(x) = 2*x\n";
            break;
        case 2:
            phi = x * x;
            cout << "Function: phi(x) = x^2\n";
            break;
        case 3:
            phi = x / 3.0;
            cout << "Function: phi(x) = x/3\n";
            break;
    }

    // Расчет итогового y
    double cos_val = cos(x * x);
    double part1 = 2.0 * a * pow(cos_val, 3);
    double sin_val = sin(x * x * x);
    double part2 = sin_val * sin_val;
    double part3 = b * phi;

    double y = part1 + part2 - part3;

    // Вывод результата
    cout << fixed << setprecision(4);
    cout << "x = " << x << '\n';
    cout << "phi(x) = " << phi << '\n';
    cout << "Result y = " << y << '\n';

    return 0;
}