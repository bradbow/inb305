// CreditAccount.cpp
// Models a customer credit account and contains
// accessors and mutators for credit card account 
// information. These include the ability to increment
// and decrement the account balance

#include "CreditAccount.h"


// constructor
// precondition: valid account details passed in
// postcondition: credit account is created
CreditAccount::CreditAccount(	int accountID,
								string accountName,
								double interestRate,
								double balance,
								double overdraftLimit) :
										Account(accountID,
												accountName, 
												interestRate,
												balance),
								_overdraftLimit(overdraftLimit)
{
}

// precondition: none
// postcondition: memory deallocated
CreditAccount::~CreditAccount(void)
{
}

// precondition: none
// postcondition: overdraft limit returned
double CreditAccount::getOverdraftLimit(void){

	return _overdraftLimit;
}

// precondition: valid amount passed in
// postcondition: overdraft limit set to amount
void CreditAccount::setOverdraftLimit(double amount){

	_overdraftLimit = amount;
}
// precondition: valid amount passed in
// postcondition: balance incremented by amount
void CreditAccount::incrementBalance(double amount){

	_balance += amount;
}

// precondition: valid amount passed in
// postcondition: balance decremented by amount
void CreditAccount::decrementBalance(double amount){

	_balance -= amount;
}

