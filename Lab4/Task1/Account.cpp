#include <string>
#include "Account.hpp"

using namespace std;

Account::Account(string ownerName) : Account::Account(0, 0, ownerName) { }

Account::Account(int accountNumber, double balance, string ownerName) 
    : accountNumber(accountNumber), balance(balance), ownerName(ownerName) { }

void Account::deposit(double amount) {
    this->balance += amount;
}

double Account::withdraw(double amount) {
    double diff = min(this->balance, amount);
    this->balance -= diff;
    return diff;
}

double Account::getBalance() const {
    return this->balance;
}

int Account::getAccountNumber() const {
    return this->accountNumber;
}

string Account::getOwnerName() const {
    return this->ownerName;
}
