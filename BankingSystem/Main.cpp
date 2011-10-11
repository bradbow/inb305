#include "Utils.h"
#include <iostream>
#include "TextFileDataSource.h"
#include <vector>
using namespace std;
 
int main()
{
	string fileNames [7] = {"Customers.txt", "BankClerks.txt", "SavingsAccounts.txt", "CreditAccounts.txt", "HomeLoanAccounts.txt", "blank.txt", "blank.txt"};
	TextFileDataSource tfds(fileNames);

}