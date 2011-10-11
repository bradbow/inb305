// Account.h
// Models a customer account and contains accessors
// and mutators for account information

#include "Transaction.h"
#include <string>
using std::string;

#ifndef _ACCOUNT_H
#define _ACCOUNT_H 

class Account
{
public:
	
	friend class SavingsAccount;
	friend class CreditAccount;
	friend class HomeLoanAccount;
	enum accountType { SAVINGS, CREDIT, HOME_LOAN };
	// constructor
	// precondition: valid account details passed in
	// postcondition: an account is created
	Account(int accountID,
			string accountName,
			double interestRate, 
			double balance);
	// destructor
	// precondition: none
	// postcondition: memory deallocated
	~Account(void);
	// precondition: none
	// postcondition: accountID returned
	int getAccountID(void);
	// precondition: valid accountName passed in
	// postcondition: accountName set
	void setAccountName(string accountName);
	// precondition: none
	// postcondition: accountName returned
	string getAccountName(void);
	// precondition: none
	// postcondition: interestRate returned
	double getInterestRate(void);
	// precondition: valid interestRate passed in
	// postcondition: interestRate set
	void setInterestRate(double interestRate);
	// precondition: none
	// postcondition: balance returned
	double getBalance(void);

private:
	int _accountID;
	int _customerID;
	accountType _type;
	string _accountName;
	double _interestRate;
	double _balance;
};
#endif