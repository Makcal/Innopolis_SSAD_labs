#ifndef SavingsAccount_H
#define SavingsAccount_H

#include <string>
#include "Account.hpp"

class SavingsAccount : public Account
{
protected:
    double interestRate;

public:
    SavingsAccount(std::string ownerName, double intersetRate);

    SavingsAccount(int accountNumber, double balance, std::string ownerName, double interestRate);

    void calculateInterest();
    
    double getInterestRate() const;
};
#endif
