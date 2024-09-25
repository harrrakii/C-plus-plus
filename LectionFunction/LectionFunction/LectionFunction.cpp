#include <iostream>
#include <string>
#include < Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	setlocale(0, "");
	int num; 
		cout << "введите размер массива: ";
		cin >> num; 
		int* p_darr = new int[num]; 
		for (int i = 0; i < num; i++) {
			cin >> p_darr[i];
		}
		for (int i = 1; i < num; i++) {
			if (p_darr[i] > p_darr[i - 1]) {
				cout << p_darr[i];
			}
		}
	delete[] p_darr;
	return 0;
}