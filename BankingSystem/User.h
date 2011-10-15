// User.h

#include <string>
#include "IdentifierObject.h"
using std::string;

#ifndef _USER_H
#define _USER_H 

class User : public IdentifierObject<int>
{
public:

	enum UserType
	{
		BANK_CLERK,
		CUSTOMER
	};

	friend class BankClerk;
	friend class Customer;
	friend class UserServices;
	
	// constructor
	// precondition: valid user details passed in
	// postcondition: user is created
	User(Identifier<int> userId, string password);
	// destructor
	// precondition: none
	// postcondition: memory deallocated
	~User(void);

private:

	string _password;
	string _userName;
	UserType m_utType;
};
#endif
