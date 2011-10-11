// HomeLoanAccount.cpp
// Models a customer home loan account and contains
// accessors and mutators for credit account 
// information. These include the ability to decrement 
// the account balance which may never fall below zero

#include "HomeLoanAccount.h"

// constructor
// precondition: valid account details passed in
// postcondtion: home loan account created
HomeLoanAccount::HomeLoanAccount(	int accountID,
									string accountName, 
									double interestRate,
									double balance,
									string propertyAddress, 
									repaymentOption repaymentOption, 
									double minimumRepayment) :
									Account(accountID,
											accountName, 
											interestRate,
											balance),
									_propertyAddress(propertyAddress),
									_option(repaymentOption),
									_minimumRepayment(minimumRepayment)
{
}

// destructor
// precondition: none
// postcondition: memory deallocated
HomeLoanAccount::~HomeLoanAccount(void)
{
}
// precondition: none
// postcondition: property address returned
string HomeLoanAccount::getPropertyAddress(void){

	return _propertyAddress;
}
// precondition: valid property address passed in
// postcondition: property address set
void HomeLoanAccount::setPropertyAddress(string propertyAddress){

	_propertyAddress = propertyAddress;
}
// precondition: none
// postcondition: repayment option returned
HomeLoanAccount::repaymentOption HomeLoanAccount::getRepaymentOption(void){

	return _option;
}
// precondition: valid repayment option passed in
// postcondition: repayment option set
void HomeLoanAccount::setRepaymentOption(repaymentOption option){

	_option = option;
}
// precondition: none
// precondition: minimum repayment returned
double HomeLoanAccount::getMinimumRepayment(void){

	return _minimumRepayment;
}

// precondition: valid amount passed in
// postcondition: minimum repayment set to amount
void HomeLoanAccount::setMinimumRepayment(double amount){

	_minimumRepayment = amount;
}

//precondition: valid amount passed in; amount
//is less than balance
//postcondition: balance decremented by amount
void HomeLoanAccount::decrementBalance(double amount){

	_balance -= amount;
}
