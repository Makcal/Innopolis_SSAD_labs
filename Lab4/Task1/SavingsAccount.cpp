#include <string>
#include "Account.hpp"
#include "SavingsAccount.hpp"

using namespace std;

SavingsAccount::SavingsAccount(string ownerName, double intersetRate) : Account(ownerName), interestRate(interestRate) {}

SavingsAccount::SavingsAccount(int accountNumber, double balance, string ownerName, double interestRate) 
    : Account(accountNumber, balance, ownerName), interestRate(interestRate) { }

void SavingsAccount::calculateInterest() {
    this->deposit(this->getBalance() * this->interestRate / 100);
}

double SavingsAccount::getInterestRate() const {
    return this->interestRate;
}
