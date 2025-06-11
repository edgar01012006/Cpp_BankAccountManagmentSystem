#include <iostream>
#include <string>
#include "BankAccount.hpp"


BankAccount::BankAccount() : _accountHolder { "Unknown" }, _accountNumber { 0 }, _balance { 0.0 } {
    //empty
}

BankAccount::BankAccount(const BankAccount& src)
	: _accountHolder { src._accountHolder }, _accountNumber { src._accountNumber }, _balance { src._balance } {
	//empty
}

BankAccount::BankAccount(const std::string& name, int accountNumber, double initialBalance) 
	: _accountHolder { name }, _accountNumber { accountNumber }, _balance { initialBalance } {
	//empty
}

BankAccount::~BankAccount() {
    //empty
}

BankAccount& BankAccount::operator=(const BankAccount& rhs) {
	if (this == &rhs) {
		return *this;
	} 
	_accountHolder = rhs._accountHolder;
	_accountNumber = rhs._accountNumber;
	_balance = rhs._balance;
	return *this;
}

void BankAccount::deposit(double amount) {
    if (amount < 0) {
		std::cout << "Can't deposit negative amount\n";
        return;
    }
    _balance += amount;
    std::cout << "Successfully deposited " << amount << " to " << _accountHolder << std::endl;
}

bool BankAccount::withdraw(double amount) {
    if (amount < 0) {
        std::cout << "Can't withdraw negative amount\n";
        return false;
    }
    if (amount > _balance) {
        std::cout << "Can't withdraw bigger ammount than balance\n";
        return false;
    }
    else {
        _balance -= amount;
        std::cout << "Successfully Withdrawed " << amount << " from " << _accountHolder << std::endl;
        return true;
    }
}

void BankAccount::display() const {
    std::cout << "AccountHolder's name is " << _accountHolder << "\t AccountNumber is " << _accountNumber << "\t Account balance = " << _balance;
}

std::string BankAccount::getAccountHolder() const {
    return _accountHolder;
}

int BankAccount::getAccountNumber() const {
    return _accountNumber;
}

double BankAccount::getAccountBalance() const {
    return _balance;
}
