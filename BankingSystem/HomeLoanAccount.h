// HomeLoanAccount.h
// Models a customer home loan account and contains
// accessors and mutators for credit account 
// information. These include the ability to decrement 
// the account balance which may never fall below zero

#include <string>
using std::string;
#include "Account.h"

#ifndef _HOME_LOAN_ACCOUNT_H
#define _HOME_LOAN_ACCOUNT_H 


class HomeLoanAccount :
	public Account
{
public:
	enum repaymentOption { WEEKLY, F_NIGHTLY, MONTHLY };

	// constructor
	// precondition: valid account details passed in
	// postcondtion: home loan account created
	HomeLoanAccount(	int accountID,
						string accountName, 
                        double interestRate,
						double balance,
                        string propertyAddress, 
                        repaymentOption repaymentOption, 
                        double minimumRepayment);
	// destructor
	// precondition: none
	// postcondition: memory deallocated
	~HomeLoanAccount(void);
	// precondition: none
	// postcondition: property address returned
	string getPropertyAddress(void);
	// precondition: valid property address passed in
	// postcondition: property address set
	void setPropertyAddress(string propertyAddress);
	// precondition: none
	// postcondition: repayment option returned
	repaymentOption getRepaymentOption(void);
	// precondition: valid repayment option passed in
	// postcondition: repayment option set
	void setRepaymentOption(repaymentOption option);
	// precondition: none
	// precondition: minimum repayment returned
	double getMinimumRepayment(void);
	// precondition: valid amount passed in
	// postcondition: minimum repayment set to amount
	void setMinimumRepayment(double amount);
	// precondition: valid amount passed in; amount
	// is less than balance
	// postcondition: balance decremented by amount
	void decrementBalance(double amount);

private:
	string _propertyAddress;
	repaymentOption _option;
	double _minimumRepayment;

};
#endif

