#pragma once
#include "DataSource.h"
#include <string>
using namespace std;

/*
	A specific implementation of a data source for the 
	banking system application using text files.

	Author: Brad Bow
*/

class TextFileDataSource : public DataSource
{
public:

	static enum Files
	{
		CUSTOMERS,
		BANK_CLERKS,
		SAVINGS_ACCOUNTS,
		CREDIT_CARD_ACCOUNTS,
		HOME_LOAN_ACCOUNTS,
		TRANSACTIONS,
		LAST_USER_ID,
		NUMBER_OF_FILES
	};

	// constructors / destructors
	TextFileDataSource(std::string rgstrFileName[]);
	virtual ~TextFileDataSource(void);

	// member methods
	virtual bool persistUsers(DataMap<User>* users);
	virtual bool persistAccounts(DataMap<Account>* accounts);
	virtual bool persistTransactions(DataMap<Transaction>* transactions);
	virtual bool persistLastUserId(int userName);
	virtual DataMap<User>* getUsersCollection(){return _users;}
	virtual DataMap<Account>* getAccountsCollection(){return _accounts;}
	virtual DataMap<Transaction>* getTransactionsCollection(){return _transactions;}
	virtual int getLastUserId(){return m_nLastUserId;}

protected: 

	// object collections
	static DataMap<User>* _users;
	static DataMap<Account>* _accounts;
	static DataMap<Transaction>* _transactions;

	// helper methods
	bool ReadTextFilesAndConstructObjects(std::string fileNames[]);
	void ConstructAndAddCustomer(string line);
	void ConstructAndAddBankClerk(string line);
	void ConstructAndAddSavingsAccount(string line);
	void ConstructAndAddCreditAccount(string line);
	void ConstructAndAddHomeLoanAccount(string line);
	void ConstructAndAddTransaction(string line);
	void ReadAndSetLastUserId(string line);

	// last user id
	int m_nLastUserId;

	// function pointer arrray
	void (TextFileDataSource::*m_pfns[TextFileDataSource::NUMBER_OF_FILES])(string);

};


