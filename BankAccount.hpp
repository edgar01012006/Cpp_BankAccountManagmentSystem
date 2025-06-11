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
        BankAccount(const BankAccount& src);
   		BankAccount(const std::string& name, int accountNumber, double initialBalance);
        ~BankAccount();
		BankAccount& operator=(const BankAccount& rhs);
		void deposit(double amount);
		bool withdraw(double ammount);
		void display() const;
        std::string getAccountHolder() const;
        int getAccountNumber() const;
        double getAccountBalance() const;
};

#endif /* BANKACCOUNT_HPP */
