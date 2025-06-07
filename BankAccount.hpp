#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <string>
#include <iostream>

class BankAccount {
    private:
        std::string _accountHolder;
        int _accountNumber;
        double _balance;
    public:
        BankAccount();
        //redecleartion BankAccount(std::string accountName, int accountNumber, double initialBalance);
        BankAccount(const BankAccount& src) 
            : _accountHolder { src._accountHolder }, _accountNumber { src._accountNumber }, _balance { src._balance }{}
        BankAccount(std::string accountName, int accountNumber, double initialBalance)
            : _accountHolder { accountName }, _accountNumber { accountNumber }, _balance { initialBalance } {}
        ~BankAccount();
};

#endif /* BANKACCOUNT_HPP */
