// Account.cpp
// Models a customer account and contains accessors
// and mutators for account information

#include "Account.h"

// constructor
// precondition: valid account details passed in
// postcondition: an account is created
Account::Account(int accountID,
				string accountName,
				double interestRate, 
				double balance){}

// destructor
// precondition: none
// postcondition: memory deallocated
Account::~Account(void){}

// precondition: none
// postcondition: accountID returned
int Account::getAccountID(void){

	return _accountID;
}

// precondition: none
// postcondition: accountName returned
string Account::getAccountName(void){

	return _accountName;
}

// precondition: valid accountName passed in
// postcondition: accountName set
void Account::setAccountName(string accountName){

	_accountName = accountName;
}

// precondition: none
// postcondition: interestRate returned
double Account::getInterestRate(void){

	return _interestRate;
}

// precondition: valid interestRate passed in
// postcondition: interestRate set
void Account::setInterestRate(double interestRate){

	_interestRate = interestRate;
}

// precondition: none
// postcondition: balance returned
double Account::getBalance(void){

	return _balance;
}
