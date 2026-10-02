#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main() {
    double a, b, z, x, phi, cos_val, sin_val, y;
    char choice_mode, choice_phi;
    int repeat;

    do {
        cout << "\nChoose mode for a, b, z:\n";
        cout << "1 - Default (a = 1.0, b = 1.0, z = 0.5)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        choice_mode = (char)_getch();
        cout << choice_mode << "\n";

        if (choice_mode == '2') {
            cout << "Enter a, b, z: ";
            cin >> a >> b >> z;
        }
        else {
            a = 1.0;
            b = 1.0;
            z = 0.5;
        }

        cout << "\nChoose phi(x):\n";
        cout << "1 - 2*x (default)\n";
        cout << "2 - x^2\n";
        cout << "3 - x/3\n";
        cout << "Choice [1/2/3] (default is 1): ";

        choice_phi = (char)_getch();
        cout << choice_phi << "\n\n";

        // Вычисление x по условию задачи
        if (z < 1.0) {
            x = z * z * z + 0.2;
            cout << "Condition used : z < 1.0 (x = z^3 + 0.2)\n";
        }
        else {
            x = z + log(z);
            cout << "Condition used : z >= 1.0 (x = z + ln(z))\n";
        }

        // Вычисление phi(x)
        switch (choice_phi) {
        case '2':
            phi = x * x;
            cout << "Function used  : phi(x) = x^2\n";
            break;
        case '3':
            phi = x / 3.0;
            cout << "Function used  : phi(x) = x/3\n";
            break;
        case '1':
        default:
            choice_phi = '1';
            phi = 2.0 * x;
            cout << "Function used  : phi(x) = 2*x\n";
            break;
        }

        // Расчет формулы
        cos_val = cos(x * x);
        sin_val = sin(x * x * x);
        y = 2.0 * a * cos_val * cos_val * cos_val + sin_val * sin_val - b * phi;

        cout << fixed << setprecision(4);
        cout << "Argument x     : " << x << '\n';
        cout << "Value phi(x)   : " << phi << '\n';
        cout << "Result y       : " << y << "\n\n";

        cout << "Do you want to continue? [y/n]: ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}