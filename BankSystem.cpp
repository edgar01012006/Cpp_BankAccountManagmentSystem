#include "BankSystem.hpp"

BankSystem::BankSystem() : _accountCount { 0 }, _accountCapacity { 0 }, _accounts { nullptr } {
	//empty
}

BankSystem::~BankSystem() {
	_accountCount = 0;
	_accountCapacity = 0;
	delete[]_accounts;
	_accounts = nullptr;
}

bool BankSystem::reserveAccountSpace() {
	if (_accountCapacity == 0) {
		_accountCapacity = 1;
		_accounts = new BankAccount[_accountCapacity];
		if (_accounts == nullptr) {
			std::cout << "Failed to reserve new Account Space\n";
			return false;
		}
		return true;
	} else if (_accountCapacity == _accountCount) {
		_accountCapacity *= 2;
		BankAccount* newAccounts = new BankAccount[_accountCapacity];
		if (newAccounts == nullptr) {
			std::cout << "Failed to reserve new Account Space\n";
			return false;
		}
		for (int i = 0; i < _accountCount; ++i) {
			newAccounts[i] = _accounts[i]; // assignment operator
		}
		_accounts = newAccounts;
		newAccounts = nullptr;
		return true;
	} else if (_accountCapacity > _accountCount) {
		std::cout << "No need to reserve new Account Space\n";
		return false;
	}
	return false;//to remove compiler warning 
}

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance) {
	if (_accountCapacity == 0) {
		if (reserveAccountSpace() == false) {
			return;
		}
	} else if(_accountCapacity == _accountCount) {
		if (reserveAccountSpace() == false) {
			return;
		}
	}
	_accounts[_accountCount]._accountHolder = name;
	_accounts[_accountCount]._accountNumber = accountNumber;
	_accounts[_accountCount]._balance = initialBalance;
	++_accountCount;
	std::cout << "Successfully added a new account\n";
}

BankAccount* BankSystem::findAccount(int accountNumber) {
	for (int i = 0; i < _accountCount; ++i) {
		if (_accounts[i]._accountNumber == accountNumber) {
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
	for (int i = 0; i < _accountCount; ++i) {
		if (flagSender == true && flagReceive == true){
			break;
		} else if (_accounts[i]._accountNumber == senderAcc) {
			tmpSender = &_accounts[i];
			flagSender = true;
		} else if (_accounts[i]._accountNumber == receiveAcc) {
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

	if (tmpSender->_balance >= amount) {
		tmpSender->_balance -= amount;
		tmpReceive->_balance += amount;
		std::cout << "Successfully transferred " << amount << " from " << tmpSender->_accountHolder << " to " << tmpReceive->_accountHolder << std::endl;
		return;
	} else {
		std::cout << "Sender's balance is not enough\n";
		return;
	}
}

void BankSystem::displayAllAccounts() const {
	for (int i = 0; i < _accountCount; ++i) {
		std::cout << _accounts[i]._accountHolder << "'s account number is " << _accounts[i]._accountNumber << " and his/her balance is " << _accounts[i]._balance << std::endl;
	}
}
