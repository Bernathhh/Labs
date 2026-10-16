#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {
    // Статический одномерный массив
    const int MAX_SIZE = 100;
    int a[MAX_SIZE];

    int n, i, first, last, sum;
    int min_val, max_val, temp;
    char choice_n, mode, choice_range;
    int repeat;

    srand((unsigned)time(0));

    do {
        // Выбор размера массива n
        cout << "\nChoose mode for array size n:\n";
        cout << "1 - Default (n = 10)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        choice_n = (char)_getch();
        cout << choice_n << "\n";

        if (choice_n == '2') {
            cout << "Enter array size n (1.." << MAX_SIZE << "): ";
            cin >> n;
            if (n <= 0 || n > MAX_SIZE) n = 10;
        }
        else {
            n = 10;
        }

        // Выбор способа заполнения
        cout << "\nChoose fill mode:\n";
        cout << "1 - Random numbers (default)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        mode = (char)_getch();
        cout << mode << "\n\n";

        if (mode == '2') {
            cout << "Enter " << n << " elements: ";
            for (i = 0; i < n; i++) {
                cin >> a[i];
            }
        }
        else {
            // Выбор диапазона для случайных чисел
            cout << "Choose range for random numbers:\n";
            cout << "1 - Default (-100..100)\n";
            cout << "2 - Enter manually\n";
            cout << "Choice [1/2] (default is 1): ";

            choice_range = (char)_getch();
            cout << choice_range << "\n";

            if (choice_range == '2') {
                cout << "Enter min and max values (e.g. -20 20): ";
                cin >> min_val >> max_val;
                if (min_val > max_val) {
                    temp = min_val;
                    min_val = max_val;
                    max_val = temp;
                }
            }
            else {
                min_val = -100;
                max_val = 100;
            }

            for (i = 0; i < n; i++) {
                a[i] = min_val + rand() % (max_val - min_val + 1);
            }
        }

        // Вывод массива
        cout << "\nArray: [ ";
        for (i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "]\n\n";

        // Поиск индекса первого положительного элемента
        first = -1;
        for (i = 0; i < n; i++) {
            if (a[i] > 0) {
                first = i;
                break;
            }
        }

        // Поиск индекса последнего положительного элемента
        last = -1;
        for (i = n - 1; i >= 0; i--) {
            if (a[i] > 0) {
                last = i;
                break;
            }
        }

        // Проверка условий задачи
        if (first == -1) {
            cout << "Result: No positive elements found. Sum cannot be calculated.\n";
        }
        else if (first == last) {
            cout << "First positive element : a[" << first << "] = " << a[first] << "\n";
            cout << "Result: Only one positive element found. Sum cannot be calculated.\n";
        }
        else if (last - first == 1) {
            cout << "First positive element : a[" << first << "] = " << a[first] << "\n";
            cout << "Last positive element  : a[" << last << "] = " << a[last] << "\n";
            cout << "Result: Elements are adjacent. No elements between them.\n";
        }
        else {
            sum = 0;
            cout << "First positive element : a[" << first << "] = " << a[first] << "\n";
            cout << "Last positive element  : a[" << last << "] = " << a[last] << "\n";
            cout << "Elements between them  : ";
            for (i = first + 1; i < last; i++) {
                cout << a[i] << " ";
                sum += a[i];
            }
            cout << "\nSum of elements between: " << sum << "\n";
        }

        cout << "\nDo you want to continue? [y/n]: ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}