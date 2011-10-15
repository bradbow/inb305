#pragma once
#include "IdMap.h"
#include "User.h"
#include "Account.h"
#include "Transaction.h"

class DataSource
{

/*
	Abstract interface for a source of application data.  
	Declares what a datasource must be able to do
	if it is to be compatable with the banking system.

	Author: Brad Bow n6532365
*/
public:
	// virtural destructor to account for different requirements in derived classes
	virtual ~DataSource(void){};

	// member functions: these are the functionalities all valid data sources must provide
	virtual bool persistUsers(IdMap<User>* users) = 0;
	virtual bool persistAccounts(IdMap<Account>* accounts) = 0;
	virtual bool persistTransactions(IdMap<Transaction>* transactions) = 0;
	virtual IdMap<User>* getUsersCollection() = 0;
	virtual IdMap<Account>* getAccountsCollection() = 0;
	virtual IdMap<Transaction>* getTransactionsCollection() = 0;

};

