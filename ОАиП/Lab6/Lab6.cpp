#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {
    int N, M, i, j;
    int min_val, max_val, temp;
    char choice_size, choice_fill;
    int repeat;

    srand((unsigned)time(0));

    do {
        cout << "\n========================================\n";

        // ШАГ 1: Размер матрицы
        cout << "[1/2] MATRIX SIZE\n";
        cout << "  1 - Default (3 rows x 4 cols)\n";
        cout << "  2 - Enter manually\n";
        cout << "Press 1 or 2: ";

        choice_size = (char)_getch();
        cout << choice_size << "\n";

        if (choice_size == '2') {
            cout << "  Rows (N): ";
            cin >> N;
            cout << "  Cols (M): ";
            cin >> M;
            if (N <= 0 || M <= 0) {
                cout << "  Wrong size -> set to default (3 x 4)\n";
                N = 3;
                M = 4;
            }
        }
        else {
            N = 3;
            M = 4;
        }

        // Выделение динамической памяти
        int** a = new int* [N];
        for (i = 0; i < N; i++) {
            a[i] = new int[M];
        }

        // ШАГ 2: Заполнение матрицы (все варианты в одном меню)
        cout << "\n[2/2] FILL MATRIX (" << N << "x" << M << ")\n";
        cout << "  1 - Random (-20 to 20)\n";
        cout << "  2 - Random (custom range)\n";
        cout << "  3 - Manual input\n";
        cout << "Press 1, 2 or 3: ";

        choice_fill = (char)_getch();
        cout << choice_fill << "\n";

        if (choice_fill == '3') {
            cout << "\nEnter numbers row by row:\n";
            for (i = 0; i < N; i++) {
                cout << "  Row " << i << " (" << M << " numbers): ";
                for (j = 0; j < M; j++) {
                    cin >> a[i][j];
                }
            }
        }
        else {
            if (choice_fill == '2') {
                cout << "  Min value: ";
                cin >> min_val;
                cout << "  Max value: ";
                cin >> max_val;
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

        // Вывод матрицы с номерами строк и столбцов
        cout << "\n--- MATRIX (" << N << "x" << M << ") ---\n\t";
        for (j = 0; j < M; j++) {
            cout << "Col " << j << "\t";
        }
        cout << "\n";

        for (i = 0; i < N; i++) {
            cout << "Row " << i << ":\t";
            for (j = 0; j < M; j++) {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }

        // Поиск особых элементов (элемент > суммы остальных в его столбце)
        int special_count = 0;
        cout << "\n--- RESULTS ---\n";

        for (j = 0; j < M; j++) {
            int col_sum = 0;
            for (i = 0; i < N; i++) {
                col_sum += a[i][j];
            }

            for (i = 0; i < N; i++) {
                int other_sum = col_sum - a[i][j];
                if (a[i][j] > other_sum) {
                    cout << "  * Special: a[" << i << "][" << j << "] = " << a[i][j]
                        << "  (in Col " << j << ": " << a[i][j] << " > " << other_sum << ")\n";
                    special_count++;
                }
            }
        }

        if (special_count == 0) {
            cout << "  No special elements found.\n";
        }
        cout << "\nTotal special elements: " << special_count << "\n";
        cout << "========================================\n";

        // Освобождение динамической памяти
        for (i = 0; i < N; i++) {
            delete[] a[i];
        }
        delete[] a;

        cout << "Press Enter or Y to run again (any other key to exit): ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}
