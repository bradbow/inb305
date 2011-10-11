#pragma once

// forward class declaration
class DataMap;

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
	virtual bool persistUsers(DataMap* users) = 0;
	virtual bool persistAccounts(DataMap* accounts) = 0;
	virtual bool persistTransactions(DataMap* transactions) = 0;
	virtual bool persistLastUserId(int userName) = 0;
	virtual DataMap* getUsersCollection() = 0;
	virtual DataMap* getAccountsCollection() = 0;
	virtual DataMap* getTransactionsCollection() = 0;
	virtual int getLastUserId() = 0;

};

