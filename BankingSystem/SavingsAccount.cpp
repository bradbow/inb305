// SavingsAccount.cpp
// Models a customer credit account and contains
// accessors and mutators for credit account 
// information. These include the ability to increment
// and decrement the account balance which may never fall
// below zero

#include "SavingsAccount.h"
#include <boost/lexical_cast.hpp>
	
// constructor
// precondition: valid account details passed in
// postcondition: savings account created
SavingsAccount::SavingsAccount(	int accountID,
								string accountName, 
								double interestRate,
								double balance) :
								Account(accountID,
										accountName,
										interestRate,
										balance)
{

}

// destructor
// precondition: none
// postcondition: memory deallocted
SavingsAccount::~SavingsAccount(void)
{
}

// precondition: valid amount passed in
// postcondition: balance incremented by amount
void SavingsAccount::incrementBalance(double amount){

	_balance += amount;
}

// precondition: valid amount passed in; amount
// is less than balance
// postcondition: balance decremented by amount
void SavingsAccount::decrementBalance(double amount){

	_balance -=amount;
}

string SavingsAccount::operator<< (const SavingsAccount &rhs){

	SavingsAccount temp = rhs;
	string delimited =
		temp.getAccountId() + "," +
		temp._accountName + "," +
		boost::lexical_cast<std::string>(temp._interestRate)
		 + "," +
		boost::lexical_cast<std::string>(temp._balance);	
		return delimited += "," + NUM_FIELDS;
}


