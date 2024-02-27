#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 5;

int main() {
    setlocale(LC_ALL, "Russian");
    float matrix[ROWS][COLS];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < ROWS; ++i) {
        cout << "Введите элементы для строки " << i + 1 << ": ";
        for (int j = 0; j < COLS; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nСреднее арифметическое элементов строк:\n";

    for (int i = 0; i < ROWS; ++i) {
        float sum = 0;
        for (int j = 0; j < COLS; ++j) {
            sum += matrix[i][j];
        }
        float average = sum / COLS;
        cout << average << endl;
    }

    return 0;
}
