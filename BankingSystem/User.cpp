//User.cpp
#include "User.h"

// constructor
// precondition: valid user details passed in
// postcondition: user is created
User::User(int userID, string password) 
	: _userId(userID), _password(password)
{
}

// destructor
// precondition: none
// postcondition: memory deallocated
User::~User(void)
{
}
