#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {
    int N, M, i, j;
    int min_val, max_val, temp;
    char choice_nm, mode, choice_range;
    int repeat;

    srand((unsigned)time(0));

    do {
        // Выбор размеров матрицы N x M (динамический двумерный массив)
        cout << "\nChoose mode for matrix size N x M:\n";
        cout << "1 - Default (3 x 4)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        choice_nm = (char)_getch();
        cout << choice_nm << "\n";

        if (choice_nm == '2') {
            cout << "Enter number of rows N: ";
            cin >> N;
            cout << "Enter number of columns M: ";
            cin >> M;
            if (N <= 0) N = 3;
            if (M <= 0) M = 4;
        }
        else {
            N = 3;
            M = 4;
        }

        // ВЫДЕЛЕНИЕ ДИНАМИЧЕСКОЙ ПАМЯТИ
        // Выделение массива указателей на строки
        int** a = new int* [N];
        for (i = 0; i < N; i++) {
            // Выделение памяти под каждую строку
            a[i] = new int[M];
        }

        // Выбор способа заполнения
        cout << "\nChoose fill mode:\n";
        cout << "1 - Random numbers (default)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        mode = (char)_getch();
        cout << mode << "\n\n";

        if (mode == '2') {
            cout << "Enter " << N * M << " elements of matrix (" << N << "x" << M << "):\n";
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    cin >> a[i][j];
                }
            }
        }
        else {
            // Выбор диапазона для случайных чисел
            cout << "Choose range for random numbers:\n";
            cout << "1 - Default (-20..20)\n";
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
                min_val = -20;
                max_val = 20;
            }

            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    a[i][j] = min_val + rand() % (max_val - min_val + 1);
                }
            }
        }

        // Вывод матрицы
        cout << "\nMatrix (" << N << "x" << M << "):\n";
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";

        // Поиск "особых" элементов по столбцам
        int special_count = 0;
        cout << "Analyzing columns...\n";

        for (j = 0; j < M; j++) {
            // Сумма всех элементов текущего столбца j
            int col_sum = 0;
            for (i = 0; i < N; i++) {
                col_sum += a[i][j];
            }

            cout << "Column " << j << " (Total sum = " << col_sum << "):\n";
            bool found_in_col = false;

            for (i = 0; i < N; i++) {
                // Сумма остальных элементов столбца без текущего
                int other_sum = col_sum - a[i][j];

                if (a[i][j] > other_sum) {
                    cout << "  -> Special: a[" << i << "][" << j << "] = " << a[i][j]
                        << " (greater than sum of others: " << other_sum << ")\n";
                    special_count++;
                    found_in_col = true;
                }
            }
            if (!found_in_col) {
                cout << "  -> No special elements in this column\n";
            }
        }

        // Вывод общего результата
        cout << "\n==================================================\n";
        cout << "Total number of special elements: " << special_count << "\n";
        cout << "==================================================\n";

        // ОЧИСТКА ДИНАМИЧЕСКОЙ ПАМЯТИ
        // Освобождение памяти строк
        for (i = 0; i < N; i++) {
            delete[] a[i];
        }
        // Освобождение массива указателей
        delete[] a;

        cout << "\nDo you want to continue? [y/n]: ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}