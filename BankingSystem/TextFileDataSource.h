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
		WITHDRAWALS,
		DEPOSITS,
		TRANSFERS,
		NUMBER_OF_FILES
	};

	// constructors / destructors
	TextFileDataSource(std::string rgstrFileName[]);
	virtual ~TextFileDataSource(void);

	// member methods
	virtual bool persistUsers(IdMap<User>* users);
	virtual bool persistAccounts(IdMap<Account>* accounts);
	virtual bool persistTransactions(IdMap<Transaction>* transactions);
	virtual IdMap<User>* getUsersCollection(){return _users;}
	virtual IdMap<Account>* getAccountsCollection(){return _accounts;}
	virtual IdMap<Transaction>* getTransactionsCollection(){return _transactions;}

protected: 

	// object collections
	static IdMap<User>* _users;
	static IdMap<Account>* _accounts;
	static IdMap<Transaction>* _transactions;

	// helper methods
	bool ReadTextFilesAndConstructObjects(std::string fileNames[]);
	void ConstructAndAddCustomer(string line);
	void ConstructAndAddBankClerk(string line);
	void ConstructAndAddSavingsAccount(string line);
	void ConstructAndAddCreditAccount(string line);
	void ConstructAndAddHomeLoanAccount(string line);
	void ConstructAndAddWithdrawalTransaction(string line);
	void ConstructAndAddDepositTransaction(string line);
	void ConstructAndAddTransferTransaction(string line);

	// last user id
	int m_nLastUserId;

	// function pointer arrray
	void (TextFileDataSource::*m_pfns[TextFileDataSource::NUMBER_OF_FILES])(string);

};


