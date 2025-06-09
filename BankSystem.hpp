#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP
#include <iostream>
#include <string>
#include <vector>
#include "BankAccount.hpp"

class BankSystem {
	private:
        std::vector<BankAccount> _accounts;
	public:
		void addAccount(const std::string& name, int accountNumber, double initialBalance);
		BankAccount* findAccount(int accountNumber);
		void transferFunds(int senderAcc, int receiverAcc, double amount);
		void displayAllAccounts() const;
};

#endif /* BANKSYSTEM_HPP */
