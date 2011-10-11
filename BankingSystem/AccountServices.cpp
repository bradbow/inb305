// AccountServices.cpp
// Provides services to open, close, retrieve and modify customer 
// accounts. Uses the Singleton Pattern to ensure there is only
// ever one AccountServices

#include "AccountServices.h"
#include "Customer.h"
#include <sstream>

using std::stringstream;

AccountServices* AccountServices::_accountServicesInstance = NULL;

// precondition: none
// postcondition: an AccountSerices is returned, if none is alreay
// available one is created then returned
AccountServices *AccountServices::instance(void){

	if(_accountServicesInstance == NULL){
	
		_accountServicesInstance = new AccountServices;
		return _accountServicesInstance;
	}		
	return _accountServicesInstance;
}

// precondition: valid parameters passed in
// postcondition: a savings account is created and returned
SavingsAccount *AccountServices::createSavingsAccount (int accountID, string accountName, 
									double interestRate, double balance){

	return new SavingsAccount(	accountID, 
								accountName, 
								interestRate, 
								balance);
}

// precondition: valid parameters passed in
// postcondition: a credit account is created and returned
CreditAccount *AccountServices::createCreditCardAccount (int accountID, string accountName, 
                                   double interestRate, double balance,
								   double overdraftLimit){

	return new CreditAccount(	accountID,
								accountName, 
								interestRate, 
								balance, 
								overdraftLimit);
}

// precondition: valid parameters passed in
// postcondition: a home loan account is created and returned
HomeLoanAccount *AccountServices::createHomeLoanAccount (int accountID, string accountName, 
                                   double interestRate, double balance,
                                   string propertyAddress, 
                                   HomeLoanAccount::repaymentOption option, 
								   double minimumRepayment){

	return new HomeLoanAccount(	accountID,
								accountName,
								interestRate,
								balance,
								propertyAddress,
								option,
								minimumRepayment);
}

// precondition: valid accountID with a zero balance is passed in
// postcondition: account matching accountID is closed 
void AccountServices::closeAccount(int accountID){

}

// precondition: valid accountType and accountID are passed in
// postcondition: old details are replaced by new
void AccountServices::changeAccountDetails(accountType type, string details[ ], int accountID){

	//Account *change = getAccount(accountID);

}

//// precondition: valid accountID passed in
//// postcondition: Account matching accountID returned
//Account *getAccount(int accountID){
//
//	Account *account = new Account(accountID, "accountName", 0.0, 0.0);
//	return account;
//}

// precondition: valid transaction passed in
// postcondition: changes made to accounts contained within
// transaction
//void AccountServices::performTransaction(Transaction* account) throws Exception{}

// precondition: valid customerID passed in
// postcondition: list of accounts matching customerID returned
list<Account*> AccountServices::getCustomerAccounts(int customerID){

	Customer customer(customerID, "password", "name", "address", "phoneNumber");
	//Customer customer = (Customer*)(getUser(userID));
	list<int> accountNumbers = customer.getAccounts();
	list<Account*> accounts;
	// retrieve the matching account for each of the the accountNumbers and add to accounts
	return accounts;
}



