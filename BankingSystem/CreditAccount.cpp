// CreditAccount.cpp
// Models a customer credit account and contains
// accessors and mutators for credit card account 
// information. These include the ability to increment
// and decrement the account balance

#include "CreditAccount.h"
#include <boost/lexical_cast.hpp>


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

string CreditAccount::operator<< (const CreditAccount &rhs){

	CreditAccount temp = rhs;
	string delimited =
		temp._accountID.getId() + "," +
		temp._accountName + "," +
		boost::lexical_cast<std::string>(temp._interestRate)
		 + "," +
		boost::lexical_cast<std::string>(temp._balance) + "," +
		boost::lexical_cast<std::string>(temp._overdraftLimit);
 		return delimited;
}

