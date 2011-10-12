#pragma once
#include "DataSource.h"

class DataInterface
{
public:

	static DataInterface* getInstance();
	static void loadDataFromDataSource(DataSource* ds);
	static void saveDataToDataSource();
	~DataInterface(void);

private:

	DataInterface();

	// data source
	static DataSource* _src;
	
	// instance
	static DataInterface* _data;

	// data collections
	static DataMap<User>* _users;
	static DataMap<Account>* _accounts;
	static DataMap<Transaction>* _transactions;

};


