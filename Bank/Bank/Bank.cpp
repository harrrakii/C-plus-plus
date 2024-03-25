#include <iostream>
#include <string>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

class BankAccount {
    friend bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount);
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accountNumber, double balance, double interestRate) {
        this->accountNumber = accountNumber;
        this->balance= balance;
        this->interestRate = interestRate;
    }

    void deposit(double amount){
        if (amount > 0) {
            balance += amount;
        }
        else {
            cout << "Неверное значение суммы" << endl;
        }
    }

    void withDraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
        }
        else {
            cout << "Ошибка снятия средств для счета. Проверьте сумму снятия";
        }
    }

    double getBalance() {
        return balance;
    }
    
    int getInterest() {
        if (interestRate > 0) {
            return balance * interestRate * (1.0 / 12);
        }
    }

    void setInterestRate(double _interestRate) {
        if (_interestRate >= 0) {
            interestRate = _interestRate;
        }
        else {
            cout << "Неверное значение процентной ставки" << endl;
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
    if (amount > 0 && fromAccount.balance >= amount) {
        fromAccount.balance -= amount;
        toAccount.balance += amount;
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    BankAccount account1(111, 1000.0, 0.05);
    BankAccount account2(112, 1001.0, 0.06);
    
    cout << "Баланс 1 аккаунта: " << account1.getBalance() << endl;
    cout << "Баланс 2 аккаунта: " << account2.getBalance() << endl;
    
    account1.deposit(500);
    cout << "Баланс аккаунта 1 после пополнения: " << account1.getBalance() << endl;

    account1.withDraw(100);
    cout << "Баланс аккаунта 1 после снятия: " << account1.getBalance() << endl;

    cout << "Проценты за месяц для аккаунта 1: " << account1.getInterest() << endl;
    account1.setInterestRate(0.08);
    cout << "Проценты для аккаунта 1: " << account1.getInterest() << endl;


    double transferAmount = 300.0;
    bool transferSuccess = transfer(account1, account2, transferAmount);

    if (transferSuccess) {
        cout << "Перевод успешен" << endl;
    }
    else {
        cout << "Ошибка при переводе" << endl;
    }

    cout << "Баланс 1 аккаунта после перевода: " << account1.getBalance() << endl;
    cout << "Баланс 2 аккаунта после перевода: " << account2.getBalance() << endl;

    return 0;
}

