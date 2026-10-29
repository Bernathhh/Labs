#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {
    // 1. Статический одномерный массив
    const int MAX_SIZE = 100;
    int a[MAX_SIZE];

    int n, i, first, last, sum;
    int min_val, max_val, temp;
    char choice_n, mode, choice_range;
    int repeat;

    srand((unsigned)time(0));

    do {
        // 2. Выбор размера массива n[cite: 1]
        cout << "\nChoose mode for array size n:\n";
        cout << "1 - Default (n = 10)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        choice_n = (char)_getch();
        cout << choice_n << "\n";

        if (choice_n == '2') {
            cout << "Enter array size n (1.." << MAX_SIZE << "): ";

            // >>>>>>>>>>>>>>>>> ДОБАВЛЕННЫЙ БЛОК: ЗАЩИТА ВВОДА РАЗМЕРА N >>>>>>>>>>>>>>>>>
            while (!(cin >> n) || n <= 0 || n > MAX_SIZE) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid size! Enter integer n (1.." << MAX_SIZE << "): ";
            }
            // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        }
        else {
            n = 10;
        }

        // 3. Выбор способа заполнения[cite: 1]
        cout << "\nChoose fill mode:\n";
        cout << "1 - Random numbers (default)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        mode = (char)_getch();
        cout << mode << "\n\n";

        if (mode == '2') {
            cout << "Enter " << n << " elements: ";
            for (i = 0; i < n; i++) {

                // >>>>>>>>>>>>>>>>> ДОБАВЛЕННЫЙ БЛОК: ЗАЩИТА ОТ ВВОДА БУКВ В МАССИВ >>>>>>>>>>>>>>>>>
                while (!(cin >> a[i])) {
                    cin.clear();             // Сброс флага ошибки потока ввода
                    cin.ignore(1000, '\n');  // Очистка некорректных символов (букв) из буфера
                    cout << "Letters detected! Enter an integer for a[" << i << "]: ";
                }
                // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            }
        }
        else {
            // Выбор диапазона для генератора[cite: 1]
            cout << "Choose range for random numbers:\n";
            cout << "1 - Default (-100..100)\n";
            cout << "2 - Enter manually\n";
            cout << "Choice [1/2] (default is 1): ";

            choice_range = (char)_getch();
            cout << choice_range << "\n";

            if (choice_range == '2') {
                cout << "Enter min and max values (e.g. -20 20): ";

                // >>>>>>>>>>>>>>>>> ДОБАВЛЕННЫЙ БЛОК: ЗАЩИТА ВВОДА ДИАПАЗОНА >>>>>>>>>>>>>>>>>
                while (!(cin >> min_val >> max_val)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid range! Enter two integers: ";
                }
                // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

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

        // 4. Вывод массива
        cout << "\nArray: [ ";
        for (i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "]\n\n";

        // 5. Поиск индекса первого положительного элемента
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

        // 6. Проверка условий задачи[cite: 1]
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

        // 7. Повтор программы (Enter, 1, y/Y, н/Н)
        cout << "\nDo you want to continue? [y/n]: ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}