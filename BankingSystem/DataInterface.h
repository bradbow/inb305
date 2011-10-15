#pragma once
#include "DataSource.h"

class DataInterface
{
public:

	static DataInterface* getInstance();
	static void loadDataFromDataSource(DataSource* ds);
	static void saveDataToDataSource();

	// getters for applicaiton objects
	// TODO Brad: implement
	static User* getUser(int userId);
	static Account* getAccount(int accountId);
	static Transaction* getTransaction(int transactionId);

	// methods to add base objects
	// TODO Brad: implement
	static void addUser(User* user);
	static void addAccount(Account* account);
	static void addTransaction(Transaction* transaction);

	// methods to remove base objects from collections
	// TODO Brad: implement
	static void removeUser(int userId);
	static void removeAccount(int accountId);
	static void removeTransaction(int transactionId);

private:

	DataInterface();

	// data source
	static DataSource* _src;
	
	// instance
	static DataInterface* _data;

	// data collections
	static IdMap<User>* _users;
	static IdMap<Account>* _accounts;
	static IdMap<Transaction>* _transactions;

};


