#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <string>
#include <iostream>

class BankAccount {
    public:
        std::string _accountHolder;
        int _accountNumber;
        double _balance;
    public:
        BankAccount();
        BankAccount(const BankAccount& src);
   		BankAccount(std::string name, int accountNumber, double initialBalance);
        ~BankAccount();
		BankAccount& operator=(const BankAccount& rhs);
		void deposit(double amount);
		bool withdraw(double ammount);
		void display() const;
};

#endif /* BANKACCOUNT_HPP */
