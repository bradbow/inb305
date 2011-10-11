// AccountServices.h
// Provides services to open, close, retrieve and modify customer 
// accounts.

#include "Account.h"
#include "SavingsAccount.h"
#include "HomeLoanAccount.h"
#include "CreditAccount.h"

#include <list>
using namespace std;

#include <string>
using std::string;

#ifndef _ACCOUNT_SERVICES_H
#define _ACCOUNT_SERVICES_H
class AccountServices
{
public:

	enum accountType{ SAVINGS_ACC, CREDIT_ACC, HOME_LOAN_ACC};

	// precondition: none
	// postcondition: instanceFlag is set to false
	~AccountServices(void){}
	// employs singleton pattern to ensure that there is only ever one
	// AccountServices instance
	// precondition: none
	// postcondition: an AccountSerices is returned, if none is alreay
	// available one is created then returned
	AccountServices *instance(void);
	// precondition: valid parameters passed in
	// postcondition: a savings account is created and returned
	SavingsAccount *createSavingsAccount (int accountID, string accountName, 
                              double interestRate, double balance);
	// precondition: valid parameters passed in
	// postcondition: a credit account is created and returned
	CreditAccount *createCreditCardAccount (int accountID, string accountName, 
                                   double interestRate, double balance,
                                   double overdraftLimit);
	// precondition: valid parameters passed in
	// postcondition: a home loan account is created and returned
	HomeLoanAccount *createHomeLoanAccount (int accountID, string accountName, 
                                   double interestRate, double balance,
                                   string propertyAddress, 
                                   HomeLoanAccount::repaymentOption option, 
                                   double minimumRepayment);

	// precondition: valid accountID with a zero balance is passed in
	// postcondition: account matching accountID is closed 
	void closeAccount(int accountID);
	// precondition: valid accountType and accountID are passed in
	// postcondition: old details are replaced by new
	void changeAccountDetails(accountType type, string details[ ], int accountID);
	// precondition: valid accountID passed in
	// postcondition: Account matching accountID returned
	Account *getAccount(int accountID);
	// precondition: valid transaction passed in
	// postcondition: changes made to accounts contained within
	// transaction
	//void performTransaction(Transaction* account) throws Exception;
	// precondition: valid customerID passed in
	// postcondition: list of accounts matching customerID returned
	list<Account*> getCustomerAccounts(int customerID);


private:
	static AccountServices* _accountServicesInstance;
	// constructor
	// precondition: none
	// postcondition: creates instance of AccountServices
	AccountServices(){}	
};
#endif

