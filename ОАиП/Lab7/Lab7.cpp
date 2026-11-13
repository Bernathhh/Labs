#include <iostream>
#include <conio.h>

using namespace std;

void Input(char*);

int main() {
    char str[81];
    char def[] = "0101 110 001100 1 1010";
    char choice;
    int i, k, start, len_group, count;
    int repeat;

    do {
        cout << "\n========================================\n";
        cout << "INPUT (only '0', '1' and spaces)\n";
        cout << "  1 - Default (\"0101 110 001100 1 1010\")\n";
        cout << "  2 - Enter manually\n";
        cout << "Press 1 or 2: ";

        choice = (char)_getch();
        cout << choice << "\n\n";

        if (choice == '2') {
            cout << "Enter string (0, 1 and spaces, Enter to finish):\n> ";
            Input(str);
            cout << "\n";
        }
        else {
            for (i = 0; def[i] != '\0'; i++) {
                str[i] = def[i];
            }
            str[i] = '\0';
        }

        cout << "\nSource string: \"" << str << "\"\n";
        cout << "\n--- RESULTS (even-length groups) ---\n";

        // Поиск и вывод групп с чётным количеством символов
        len_group = 0;
        start = 0;
        count = 0;

        for (i = 0; ; i++) {
            if (str[i] != ' ' && str[i] != '\0') {
                if (len_group == 0) {
                    start = i;
                }
                len_group++;
            }
            else {
                if (len_group > 0) {
                    if (len_group % 2 == 0) {
                        count++;
                        cout << "  " << count << ") ";
                        for (k = start; k < start + len_group; k++) {
                            cout << str[k];
                        }
                        cout << "  (length = " << len_group << ")\n";
                    }
                    len_group = 0;
                }
                if (str[i] == '\0') break;
            }
        }

        if (count == 0) {
            cout << "  No even-length groups found.\n";
        }
        else {
            cout << "\nTotal even-length groups: " << count << "\n";
        }
        cout << "========================================\n";

        cout << "Press Enter or Y to run again (any other key to exit): ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 13 || repeat == 10 || repeat == 'y' || repeat == 'Y' || repeat == '1' || repeat == 'н' || repeat == 'Н');
}

// Ввод только '0', '1' и пробела (презентация 1-6-1)
void Input(char* s) {
    int i = 0;
    while (1) {
        s[i] = _getch();
        if (s[i] == 13) break;
        if (!(s[i] == '0' || s[i] == '1' || s[i] == ' '))
            continue;
        cout << s[i];
        i++;
    }
    s[i] = '\0';
}