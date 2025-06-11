#include "BankSystem.hpp"

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance) {
	_accounts.emplace_back(BankAccount(name, accountNumber, initialBalance));
	std::cout << "Successfully added a new account\n";
}

BankAccount* BankSystem::findAccount(int accountNumber) {
	for (int i = 0; i < _accounts.size(); ++i) {
		if (_accounts[i].getAccountNumber() == accountNumber) {
			std::cout << "Successfully found the account\n";
			return &_accounts[i];
		}
	}
	std::cout << "No account available via " << accountNumber << " number\n";
	return nullptr;
}

void BankSystem::transferFunds(int senderAcc, int receiveAcc, double amount) {
	bool flagSender = false, flagReceive = false;
	BankAccount* tmpSender = nullptr;
	BankAccount* tmpReceive = nullptr;
	for (int i = 0; i < _accounts.size(); ++i) {
		if (flagSender == true && flagReceive == true){
			break;
		} else if (_accounts[i].getAccountNumber() == senderAcc) {
			tmpSender = &_accounts[i];
			flagSender = true;
		} else if (_accounts[i].getAccountNumber() == receiveAcc) {
			tmpReceive = &_accounts[i];
			flagReceive = true;
		}
	}
	if (flagSender == false) {
		std::cout << "Sender's account doesn't exist\n";
		return;
	} else if (flagReceive == false) {
		std::cout << "Receiver's account doesn't exist\n";
		return;
	}

	if (tmpSender->withdraw(amount) == true) {
		tmpReceive->deposit(amount);
		std::cout << "Successfully transferred " << amount << " from " << tmpSender->getAccountHolder() << " to " << tmpReceive->getAccountHolder() << std::endl;
		return;
	} else {
		std::cout << "Failed to transfer funds\n";
		return;
	}
}

void BankSystem::displayAllAccounts() const {
	for (int i = 0; i < _accounts.size(); ++i) {
		std::cout << _accounts[i].getAccountHolder() << "'s account number is " << _accounts[i].getAccountNumber() << " and his/her balance is " << _accounts[i].getAccountBalance() << std::endl;
	}
}
