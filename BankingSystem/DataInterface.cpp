#include "DataInterface.h"

// --------------------------------------------------------------------------------------------- //
// Static declarations

IdMap<User>* DataInterface::_users;
IdMap<Transaction>* DataInterface::_transactions;
IdMap<Account>* DataInterface::_accounts;
DataInterface* DataInterface::_data = NULL;
DataSource* DataInterface::_src = NULL;

// --------------------------------------------------------------------------------------------- //
// Constructors / Destructors / Instance Retrieval

DataInterface* DataInterface::getInstance()
{
	
	if (_data == NULL)
	{
		_data = new DataInterface();
	}

	return _data;

}

DataInterface::DataInterface()
{
}

// --------------------------------------------------------------------------------------------- //
// Member Methods

void DataInterface::loadDataFromDataSource(DataSource* ds)
{
	
	_src = ds;
	_users = _src->getUsersCollection();
	_accounts = _src->getAccountsCollection();
	_transactions = _src->getTransactionsCollection();

}

void DataInterface::saveDataToDataSource()
{

	_src->persistUsers(_users);
	_src->persistAccounts(_accounts);
	_src->persistTransactions(_transactions);

}

