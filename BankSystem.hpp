#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP
#include <iostream>
#include <string>
#include "BankAccount.hpp"

class BankSystem {
	private:
		size_t _accountCount;
		size_t _accountCapacity;
		BankAccount* _accounts;		
	public:
		bool reserveAccountSpace();
		BankSystem();
		~BankSystem();
		void addAccount(const std::string& name, int accountNumber, double initialBalance);
		BankAccount* findAccount(int accountNumber);
		void transferFunds(int senderAcc, int receiverAcc, double amount);
		void displayAllAccounts() const;
};

#endif /* BANKSYSTEM_HPP */
