#include <iostream>
#include <string>
#include "BankAccount.hpp"


BankAccount::BankAccount() {
    _accountHolder = "Unknown";
    _accountNumber = 0;
    _balance = 0.0;
}

BankAccount::~BankAccount() {
    _accountHolder = "Unknown";
    _accountNumber = 0;
    _balance = 0.0;
}

void BankAccount::deposit(double amount) {
    if (amount < 0) {
        return;
    }
    _balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if (amount < 0) {
        std::cout << "Can't withdraw negative amount\n";
        return false;
    }
    if (amount > _balance) {
        std::cout << "Can't withdraw amount bigger than balance\n";
        return false;
    }
    else {
        _balance -= amount;
        std::cout << "Successfully Withdrawed " << amount << std::endl;
        return true;
    }
}

void BankAccount::display() const {
    std::cout << "AccountHolder's name is " << _accountHolder << "\t AccountNumber is " << _accountNumber << "\t Account balance = " << _balance;
}

int main() {
}
