Bank Account Management System Simulation

BankAccount.hpp // BankAccount class definition
BankAccount.cpp // BankAccount class implementation
BankSystem.hpp // BankSystem class definition
BankSystem.cpp // BankSystem class implementation
main.cpp // Program executing

BankAccount.hpp  
	Contains private attributes(account's name, number and balance), 
	constructors(default and parameterized), destructor, and copy assignment operator(following the rule that if we have a copy constructor we should have a copy assignment operator)
	methods like deposit, withdraw, display;
BankAccount.cpp
	Implementation of constructors, destructor, copy assignment operator and methods;
BankAccount.hpp
	Contains private attributes (vector of BankAccounts),
	methods like add account, find account, transfer funds between two accounts, and display all accounts in vector;
BankAccount.cpp
	Implementation of methods;
main.cpp
	Demonstrates the use of BankSystem class;

Compile and execute
	g++ main.cpp BankAccount.cpp BankSystem.cpp
	./a.out 

