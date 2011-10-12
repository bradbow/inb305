#pragma once
#include "DataMap.h"
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
	virtual bool persistUsers(DataMap<User>* users) = 0;
	virtual bool persistAccounts(DataMap<Account>* accounts) = 0;
	virtual bool persistTransactions(DataMap<Transaction>* transactions) = 0;
	virtual DataMap<User>* getUsersCollection() = 0;
	virtual DataMap<Account>* getAccountsCollection() = 0;
	virtual DataMap<Transaction>* getTransactionsCollection() = 0;

};

