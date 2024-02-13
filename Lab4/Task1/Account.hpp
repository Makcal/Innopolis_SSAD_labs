#ifndef Account_H
#define Account_H

#include <string>

class Account
{
protected:
    int accountNumber;
    double balance;
    std::string ownerName;

public:
    Account() = default;

    Account(std::string ownerName);

    Account(int accountNumber, double balance, std::string ownerName);

    Account(Account&) = delete;

    Account& operator=(Account&) = delete;

    void deposit(double amount);

    double withdraw(double amount);

    double getBalance() const;

    int getAccountNumber() const;

    std::string getOwnerName() const;
};

#endif
