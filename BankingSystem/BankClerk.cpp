// BankClerk.cpp
// Models a bank clerk

#include "BankClerk.h"

// constructor
// precondition: valid bank clerk details passed in
// postcondition: bank clerk created
BankClerk::BankClerk(
	int userName, 
	string password) : 
User(userName, password){}

// destructor
// precondition: none
// postcondition: memory deallocated
BankClerk::~BankClerk(void)
{
}

