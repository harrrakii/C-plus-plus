#include <iostream> 
#include <Windows.h> 
using namespace std;

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int a, b;
    int operatorCal;
    bool count = true;

    do {
        cout << "Выберите действие:\n"
            << "1.Сложение\n"
            << "2.Вычитание\n"
            << "3.Частное\n"
            << "4.Произведение\n"
            << "5.Возведение в степень\n"
            << "6.Нахождения квадратного корня\n"
            << "7.Нахождение 1 процента от числа\n"
            << "8.Найти факториал числа\n"
            << "9.Выйти из программы.\n";
        cin >> operatorCal;

        switch (operatorCal) {
        case 1: {
            cout << "Введите первое число:\n";
            cin >> a;
            cout << "Введите второе число:\n";
            cin >> b;
            int с = a + b;
            cout << "Сумма чисел = " << с << endl;
            break;
        }
        case 2: {
            cout << "Введите первое число: \n";
            cin >> a;
            cout << "Введите второе число: ";
            cin >> b;
            int с = a - b;
            cout << "Разность чисел = " << с << endl;
            break;
        }
        case 3: {
            cout << "Введите первое число: \n";
            cin >> a;
            cout << "Введите второе число: ";
            cin >> b;
            if (b == 0) {
                cout << "Деление на ноль невозможно\n";
            }
            else {
                int с = a / b;
                cout << "Частное чисел = " << с << endl;
            }
            break;
        }
        case 4: {
            cout << "Введите первое число: \n";
            cin >> a;
            cout << "Введите второе число: ";
            cin >> b;
            int с = a * b;
            cout << "Произведение чисел = " << с << endl;
            break;
        }
        case 5: {
            cout << "Введите число: \n";
            cin >> a;
            cout << "Введите показатель степени:\n";
            cin >> b;
            int с = pow(a, b);
            cout << "Значение числа возведенного в степень = " << с << endl;
            break;
        }
        case 6: {
            cout << "Введите число: \n";
            cin >> a;
            double c = sqrt(a);
            cout << "Значение корня числа:" << c << endl;
            break;
        }
        case 7: {
            cout << "Введите число: \n";
            cin >> a;
            double c = a * 0.01;
            cout << "Значение одного процента от числа: " << c << endl;
            break;
        }
        case 8: {
            cout << "Введите число: \n";
            cin >> a;
            int res = 1;
            if (a >= 0) {
                for (int i = 1; i <= a; i++) {
                    res *= i;
                }
                cout << "Значение факториала: " << res << endl;
            }
            else {
                cout << "Факториал из отрицательного числа";
            }
            break;
        }
        case 9: {
            count = false;
            cout << "Выход из программы" << endl;
            break;
        }
        default: {
            cout << "Неизвестная команда" << endl;
            break;
        }
        }
    } while (count);
    return 0;
}
