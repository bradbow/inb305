#include "DataInterface.h"

// --------------------------------------------------------------------------------------------- //
// Static declarations

DataMap<User>* DataInterface::_users;
DataMap<Transaction>* DataInterface::_transactions;
DataMap<Account>* DataInterface::_accounts;
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

DataInterface::~DataInterface(void)
{

	delete _data;

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

