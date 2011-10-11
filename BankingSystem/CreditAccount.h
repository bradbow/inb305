// CreditAccount.h
// Models a customer credit account and contains
// accessors and mutators for credit account 
// information. These include the ability to increment
// and decrement the account balance, which may never exceed
// the overdraft limit.

#include "Account.h"
#include <string>
using std::string;

#ifndef _CREDIT_ACCOUNT_H
#define _CREDIT_ACCOUNT_H 

class CreditAccount :
	public Account
{
public:
	// constructor
	// precondition: valid account details passed in
	// postcondition: credit account is created
	CreditAccount(	int accountID,
					string accountName,
					double interestRate,
					double balance,
					double overdraftLimit);
	// precondition: none
	// postcondition: memory deallocated
	~CreditAccount(void);
	// precondition: none
	// postcondition: overdraft limit returned
	double getOverdraftLimit(void);
	// precondition: valid amount passed in
	// postcondition: overdraft limit set to amount
	void setOverdraftLimit(double amount);
	// precondition: valid amount passed in
	// postcondition: balance incremented by amount
	void incrementBalance(double amount);
	// precondition: valid amount passed in
	// postcondition: balance decremented by amount
	void decrementBalance(double amount);

private:
	double _overdraftLimit;
	
};

#endif
