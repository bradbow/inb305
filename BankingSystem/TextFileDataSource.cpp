#include "TextFileDataSource.h"
#include "IdMap.h"
#include "User.h"
#include "BankClerk.h"
#include "Customer.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "HomeLoanAccount.h"
#include "Withdrawal.h"
#include "Deposit.h"
#include "Transfer.h"
#include <fstream>
#include <string>
#include "Utils.h"

using namespace std;
IdMap<User>* TextFileDataSource::_users;
IdMap<Account>* TextFileDataSource::_accounts;
IdMap<Transaction>* TextFileDataSource::_transactions;

// --------------------------------------------------------------------------------------------- //
// constructors / destructors

TextFileDataSource::TextFileDataSource(std::string rgstrFileNames[])
{

	// fill out function pointer array
	m_pfns[CUSTOMERS] = &TextFileDataSource::ConstructAndAddCustomer;
	m_pfns[BANK_CLERKS] = &TextFileDataSource::ConstructAndAddBankClerk;
	m_pfns[SAVINGS_ACCOUNTS] = &TextFileDataSource::ConstructAndAddSavingsAccount;
	m_pfns[CREDIT_CARD_ACCOUNTS] = &TextFileDataSource::ConstructAndAddCreditAccount;
	m_pfns[HOME_LOAN_ACCOUNTS] = &TextFileDataSource::ConstructAndAddHomeLoanAccount;
	m_pfns[WITHDRAWALS] = &TextFileDataSource::ConstructAndAddWithdrawalTransaction;
	m_pfns[DEPOSITS] = &TextFileDataSource::ConstructAndAddDepositTransaction;
	m_pfns[TRANSFERS] = &TextFileDataSource::ConstructAndAddTransferTransaction;

	// Read txt files and populate collections
	ReadTextFilesAndConstructObjects(rgstrFileNames);

}

TextFileDataSource::~TextFileDataSource()
{
}

// --------------------------------------------------------------------------------------------- //
// member methods

bool TextFileDataSource::persistUsers(IdMap<User>* users)
{
	return true;
}

bool TextFileDataSource::persistAccounts(IdMap<Account>* accounts)
{
	return true;
}

bool TextFileDataSource::persistTransactions(IdMap<Transaction>* transactions)
{
	return true;
}



// --------------------------------------------------------------------------------------------- //
// helper / utility methods

bool TextFileDataSource::ReadTextFilesAndConstructObjects(string fileNames[])
{
	
	for (int nFile = 0; nFile < NUMBER_OF_FILES; nFile++)
	{
		std::ifstream rfsFile;
		rfsFile.open(fileNames[nFile].c_str());
		string line;

		if (rfsFile)
		{
			// read lines and create objects
			while (!rfsFile.eof())
			{
				getline(rfsFile, line);
				(this->*m_pfns[nFile])(line);					// call appropriate fnc
			}
		}
		else 
		{
			// TODO Brad: file does not exist - exception?
		}

		rfsFile.close();
	}

	
	// TODO Brad: return boolean or exception handling?
	return true;
	 
}

void TextFileDataSource::ConstructAndAddCustomer(string line)
{
	enum 
	{
		USER_ID,
		PASSWORD,
		NAME,
		ADDRESS,
		PHONE_NUMBER,
		ACCOUNT_IDS,
		NUM_FIELDS
	};
	
	vector<string> lineSplit = StringUtils::splitString(line, ',');
	vector<string> accountIds = StringUtils::splitString(lineSplit[ACCOUNT_IDS], ';');

	// create customer
	Customer c
	(
		TypeConverter(lineSplit[USER_ID]),
		lineSplit[PASSWORD],
		lineSplit[NAME],
		lineSplit[ADDRESS],
		lineSplit[PHONE_NUMBER]
	);

	// add account ids
	vector<string>::iterator vit;
	for (vit = accountIds.begin(); vit != accountIds.end(); ++vit)
	{
		c.addAccount(TypeConverter(*vit));
	}

	_users->Add(c);

}

void TextFileDataSource::ConstructAndAddBankClerk(string line)
{
	enum
	{
		USER_ID,
		PASSWORD,
		NUM_FIELDS
	};

	vector<string> lineSplit = StringUtils::splitString(line, ',');

	BankClerk bc
	(
		TypeConverter(lineSplit[USER_ID]),
		lineSplit[PASSWORD]
	);

	_users->Add(bc);
}

void TextFileDataSource::ConstructAndAddSavingsAccount(string line)
{
	enum
	{
		ACCOUNT_ID,
		ACCOUNT_NAME,
		INTEREST_RATE,
		BALANCE,
		NUM_FIELDS
	};

	vector<string> lineSplit = StringUtils::splitString(line, ',');

	SavingsAccount sa
	(
		TypeConverter(lineSplit[ACCOUNT_ID]),
		lineSplit[ACCOUNT_NAME],
		TypeConverter(lineSplit[INTEREST_RATE]),
		TypeConverter(lineSplit[BALANCE])
	);

	_accounts->Add(sa);

}

void TextFileDataSource::ConstructAndAddCreditAccount(string line)
{
	enum
	{
		ACCOUNT_ID,
		ACCOUNT_NAME,
		INTEREST_RATE,
		BALANCE,
		LIMIT,
		NUM_FIELDS
	};

	vector<string> lineSplit = StringUtils::splitString(line, ',');

	CreditAccount ca
	(
		TypeConverter(lineSplit[ACCOUNT_ID]),
		lineSplit[ACCOUNT_NAME],
		TypeConverter(lineSplit[INTEREST_RATE]),
		TypeConverter(lineSplit[BALANCE]),
		TypeConverter(lineSplit[LIMIT])
	);

	_accounts->Add(ca);

}

void TextFileDataSource::ConstructAndAddHomeLoanAccount(string line)
{
	enum
	{
		ACCOUNT_ID,
		ACCOUNT_NAME,
		INTEREST_RATE,
		BALANCE,
		PROPERTY_ADDRESS,
		REPAYMENT_OPTION,
		MIN_REPAYMENT,
		NUM_FIELDS
	};

	vector<string> lineSplit = StringUtils::splitString(line, ',');

	// TODO Brad & Jeff: Dangerous....
	int nOption = TypeConverter(lineSplit[REPAYMENT_OPTION]);
	HomeLoanAccount::repaymentOption option = static_cast<HomeLoanAccount::repaymentOption>(nOption);

	HomeLoanAccount hla
	(
		TypeConverter(lineSplit[ACCOUNT_ID]),
		lineSplit[ACCOUNT_NAME],
		TypeConverter(lineSplit[INTEREST_RATE]),
		TypeConverter(lineSplit[BALANCE]),
		lineSplit[PROPERTY_ADDRESS],
		option,
		TypeConverter(lineSplit[MIN_REPAYMENT])
	);

	_accounts->Add(hla);

}

void TextFileDataSource::ConstructAndAddWithdrawalTransaction(string line)
{

	enum
	{
		ID,
		AMOUNT,
		CUSTOMER_ID,
		DATE,
		ACCOUNT_ID,
		NUM_FIELDS
	};

	vector<string> lineSplit = StringUtils::splitString(line, ',');
	date dt = from_string(lineSplit[DATE]);

	Withdrawal w
	(
		TypeConverter(lineSplit[ID]),
		TypeConverter(lineSplit[AMOUNT]),
		TypeConverter(lineSplit[CUSTOMER_ID]),
		dt,
		TypeConverter(lineSplit[ACCOUNT_ID])
	);

	_transactions->Add(w);

}

void TextFileDataSource::ConstructAndAddDepositTransaction(string line)
{

	enum
	{
		ID,
		AMOUNT,
		CUSTOMER_ID,
		DATE,
		ACCOUNT_ID,
		NUM_FIELDS
	};

	vector<string> lineSplit = StringUtils::splitString(line, ',');
	date dt = from_string(lineSplit[DATE]);

	Deposit d
	(
		TypeConverter(lineSplit[ID]),
		TypeConverter(lineSplit[AMOUNT]),
		TypeConverter(lineSplit[CUSTOMER_ID]),
		dt,
		TypeConverter(lineSplit[ACCOUNT_ID])
	);

	_transactions->Add(d);

}

void TextFileDataSource::ConstructAndAddTransferTransaction(string line)
{

	enum
	{
		ID,
		AMOUNT,
		CUSTOMER_ID,
		DATE,
		TO_ACCOUNT_ID,
		FROM_ACCOUNT_ID,
		NUM_FIELDS
	};

	vector<string> lineSplit = StringUtils::splitString(line, ',');
	date dt = from_string(lineSplit[DATE]);

	Transfer t
	(
		TypeConverter(lineSplit[ID]),
		TypeConverter(lineSplit[AMOUNT]),
		TypeConverter(lineSplit[CUSTOMER_ID]),
		dt,
		TypeConverter(lineSplit[TO_ACCOUNT_ID]),
		TypeConverter(lineSplit[FROM_ACCOUNT_ID])
	);

	_transactions->Add(t);

}

// --------------------------------------------------------------------------------------------- //


