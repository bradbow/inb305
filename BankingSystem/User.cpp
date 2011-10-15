//User.cpp
#include "User.h"

// constructor
// precondition: valid user details passed in
// postcondition: user is created
User::User(Identifier<int> userID, string password) 
	: IdentifierObject(userID), _password(password)
{
}

// destructor
// precondition: none
// postcondition: memory deallocated
User::~User(void)
{
}
