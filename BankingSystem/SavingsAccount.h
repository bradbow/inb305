// SavingsAccount.h
// Models a customer credit account and contains
// accessors and mutators for credit account 
// information. These include the ability to increment
// and decrement the account balance which may never fall
// below zero


#include <string>
using std::string;
#include "Account.h"

#ifndef _SAVINGS_ACCOUNT_H
#define _SAVINGS_ACCOUNT_H 


class SavingsAccount :
	public Account
{
public:
	// constructor
	// precondition: valid account details passed in
	// postcondition: savings account created
	SavingsAccount(int accountID,
					string accountName, 
                    double interestRate,
					double balance);
	// destructor
	// precondition: none
	// postcondition: memory deallocted
	~SavingsAccount(void);
	// precondition: valid amount passed in
	// postcondition: balance incremented by amount
	void incrementBalance(double amount);
	// precondition: valid amount passed in; amount
	// is less than balance
	// postcondition: balance decremented by amount
	void decrementBalance(double amount);

private:

};
#endif

