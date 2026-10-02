#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main() {
    //        Вариант 4
    //    x      y       z
    // 0.4e4 -0.875 -0.475e-3

    double x, y, z, base, exponent, part1, z2, z3, z4, part2, result;
    char choice_mode;
    int repeat;

    do {
        cout << "\nChoose mode for x, y, z:\n";
        cout << "1 - Default (x = 0.4e4, y = -0.875, z = -0.475e-3)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        choice_mode = (char)_getch();
        cout << choice_mode << "\n";

        if (choice_mode == '2') {
            cout << "Enter x, y, z: ";
            cin >> x >> y >> z;
        }
        else {
            x = 0.4e4;
            y = -0.875;
            z = -0.475e-3;
        }

        base = fabs(cos(x) - cos(y));
        exponent = 1.0 + 2.0 * pow(sin(y), 2);

        part1 = pow(base, exponent);

        z2 = z * z;
        z3 = z2 * z;
        z4 = z3 * z;
        part2 = 1.0 + z + (z2 / 2.0) + (z3 / 3.0) + (z4 / 4.0);

        result = part1 * part2;

        cout << fixed << setprecision(4);
        cout << "Result = " << result << "\n\n";

        cout << "Do you want to continue? [y/n]: ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}