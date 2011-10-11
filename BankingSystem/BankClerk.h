// BankClerk.h
// Models a bank clerk
#include "user.h"

#ifndef _BANKCLERK_H
#define _BANKCLERK_H 

class BankClerk :
	public User
{
public:
	// constructor
	// precondition: valid bank clerk details passed in
	// postcondition: bank clerk created
	BankClerk(int userName, string password);
	// destructor
	// precondition: none
	// postcondition: memory deallocated
	~BankClerk(void);

private:

};
#endif

