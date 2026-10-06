#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main() {
    double a, b, h, x, x2, y, s, r, diff;
    int n, k;
    char choice;
    int repeat;

    do {
        cout << "\nChoose mode for a, b, h:\n";
        cout << "1 - Default (a = 0.1, b = 1.0, h = 0.1)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        choice = (char)_getch();
        cout << choice << "\n";

        if (choice == '2') {
            cout << "Enter a, b, h: ";
            cin >> a >> b >> h;
        }
        else {
            a = 0.1;
            b = 1.0;
            h = 0.1;
        }

        cout << "\nChoose mode for n:\n";
        cout << "1 - Default (n = 10)\n";
        cout << "2 - Enter manually (e.g. 5 or 50)\n";
        cout << "Choice [1/2] (default is 1): ";

        choice = (char)_getch();
        cout << choice << "\n";

        if (choice == '2') {
            cout << "Enter n: ";
            cin >> n;
        }
        else {
            n = 10;
        }

        cout << fixed << setprecision(6);
        cout << "\n"
            << setw(10) << "x"
            << setw(16) << "Y(x)"
            << setw(16) << "S(x)"
            << setw(16) << "|Y - S|\n\n";

        for (x = a; x <= b + h / 2; x += h) {
            y = cos(x);
            r = s = 1.0;
            x2 = x * x;

            for (k = 1; k <= n; ++k) {
                r = -r * x2 / ((2 * k - 1) * (2 * k));
                s += r;
            }

            diff = fabs(y - s);

            cout << setw(10) << x
                << setw(16) << y
                << setw(16) << s
                << setw(16) << diff << '\n';
        }

        cout << "\nDo you want to continue? [y/n]: ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}