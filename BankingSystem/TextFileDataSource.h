#pragma once
#include "DataSource.h"
#include <string>
using namespace std;

/*
	A specific implementation of a data soure for the 
	banking system application using text files.

	Author: Brad Bow
*/

class TextFileDataSource : public DataSource
{
public:

	enum Files
	{
		USERS, 
		ACCOUNTS,
		TRANSACTIONS,
		LAST_USER_ID,
		NUMBER_OF_FILES
	};

	enum UserDetails
	{
		USER_NAME,
		PASSWORD,
		USER_TYPE
	};
	
	enum CustomerDetails
	{
		NAME,
		ADDRESS,
		PHONE_NUMBER, 
		ACCOUNT_IDS
	};

	// constructors / destructors
	TextFileDataSource(std::wstring rgstrFileName[]);
	virtual ~TextFileDataSource(void);

	// member methods
	virtual bool persistUsers(DataMap* users);
	virtual bool persistAccounts(DataMap* accounts);
	virtual bool persistTransactions(DataMap* transactions);
	virtual bool persistLastUserId(int userName);
	virtual DataMap* getUsersCollection(){return m_pdmUsers;}
	virtual DataMap* getAccountsCollection(){return m_pdmAccounts;}
	virtual DataMap* getTransactionsCollection(){return m_pdmTransactions;}
	virtual int getLastUserId(){return m_nLastUserId;}

protected: 

	// object collections
	static DataMap* m_pdmUsers;
	static DataMap* m_pdmAccounts;
	static DataMap* m_pdmTransactions;

	// last user id
	int m_nLastUserId;

	// helper function
	bool ReadTextFilesAndConstructObjects(std::wstring strFileName[]);

	// function pointer arrray
	void (*m_pfns[TextFileDataSource::NUMBER_OF_FILES])(string, TextFileDataSource* tfds);

};

