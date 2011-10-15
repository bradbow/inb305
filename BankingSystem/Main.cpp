#include "Utils.h"
#include <iostream>
#include "TextFileDataSource.h"
#include <vector>
using namespace std;
 
int main()
{
	string fileNames [8] = {"Customers.txt", "BankClerks.txt", "SavingsAccounts.txt", "CreditAccounts.txt", "HomeLoanAccounts.txt", "WithdrawalTransactions.txt", "DepositTransactions.txt", "TransferTransactions.txt"};
	TextFileDataSource* ds = dynamic_cast<TextFileDataSource*>(TextFileDataSource::getInstance());
	ds->setFileNames(fileNames);
	ds->loadData();

	//tfds.loadData();

}