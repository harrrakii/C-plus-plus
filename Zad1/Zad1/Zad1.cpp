#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <cctype>
using namespace std;

string reverse(string& inputStr) {
    string reversed_word = inputStr;
    reverse(reversed_word.begin(), reversed_word.end());
    return reversed_word;
}

string removeVowels(string& inputStr) {
    string res;
    for (char c : inputStr) {
        if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' &&
            tolower(c) != 'o' && tolower(c) != 'u' && tolower(c) != 'y') {
            res += c;
        }
    }
    return res;
}

string removeConsonants(string& inputStr) {
    string res;
    for (char c : inputStr) {
        if ((tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' ||
            tolower(c) == 'o' || tolower(c) == 'u' || tolower(c) == 'y')) {
            res += c;
        }
    }
    return res;
}

   string shuffle(string& inputStr) {
    string shuffled_word = inputStr;
    random_device rd;
    mt19937 gen(rd());
    shuffle(shuffled_word.begin(), shuffled_word.end(), gen);
    return shuffled_word;
}


int main() {
    string inputStr;
    cout << "Enter the requit text: ";
    cin >> inputStr;

    int numOperator;
    cout << "Choose an action:\n"
        << "1. Print the word in reverse.\n"
        << "2. Print the word without vowels.\n"
        << "3. Print the word without consonants.\n"
        << "4. Shuffle the letters of the given word randomly.\n";
    cin >> numOperator;
    switch (numOperator)
    {
        case 1: {
            cout << reverse(inputStr) << endl;
            break;
        }
        case 2: {
            cout << removeVowels(inputStr) << endl;
            break;
        }
        case 3: {
            cout << removeConsonants(inputStr) << endl;
            break;
        }
        case 4: {
            cout << shuffle(inputStr) << endl;
            break;
        }
        default: {
            cout << "Incorrect input";
            break;
        }
    }
}
