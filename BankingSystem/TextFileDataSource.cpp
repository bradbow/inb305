#include "TextFileDataSource.h"
#include "DataMap.h"
#include "User.h"
#include "BankClerk.h"
#include "Customer.h"
#include <fstream>
#include <string>
#include "Utils.h"

// comment here

using namespace std;

// prototypes
void ConstructAndAddUser(string strLine, TextFileDataSource* tfds);
void ConstructAndAddAccount(string strLine, TextFileDataSource* tfds);
void ConstructAndAddTransaction(string strLine, TextFileDataSource* tfds);
void ReadAndSetLastUserId(string strLine, TextFileDataSource* tfds);
DataMap* TextFileDataSource::m_pdmUsers;
DataMap* TextFileDataSource::m_pdmAccounts;
DataMap* TextFileDataSource::m_pdmTransactions;

// --------------------------------------------------------------------------------------------- //
// constructors / destructors

TextFileDataSource::TextFileDataSource(std::wstring rgstrFileNames[])
{

	// fill out function pointer array
	m_pfns[USERS] = &ConstructAndAddUser;
	m_pfns[ACCOUNTS] = &ConstructAndAddAccount;
	m_pfns[TRANSACTIONS] = &ConstructAndAddTransaction;
	m_pfns[LAST_USER_ID] = &ReadAndSetLastUserId;

	// Read txt files and populate collections
	ReadTextFilesAndConstructObjects(rgstrFileNames);

	int one = TextFileDataSource::ACCOUNTS;
	std::string strTemp;

}

TextFileDataSource::~TextFileDataSource()
{
}

// --------------------------------------------------------------------------------------------- //
// member methods

bool TextFileDataSource::persistUsers(DataMap* users)
{
	return true;
}

bool TextFileDataSource::persistAccounts(DataMap* accounts)
{
	return true;
}

bool TextFileDataSource::persistTransactions(DataMap* transactions)
{
	return true;
}

bool TextFileDataSource::persistLastUserId(int userId)
{
	return true;
}


// --------------------------------------------------------------------------------------------- //
// helper / utility methods

bool TextFileDataSource::ReadTextFilesAndConstructObjects(std::wstring rgstrFileNames[])
{
	
	for (int nFile = 0; nFile = NUMBER_OF_FILES; nFile++)
	{
		std::ifstream rfsFile;
		rfsFile.open(rgstrFileNames[nFile].c_str());
		string strLine;
		

		if (rfsFile)
		{
			// read lines and create objects
			while (!rfsFile.eofbit)
			{
				getline(rfsFile, strLine);
				(m_pfns[nFile])(strLine, this);					// call appropriate fnc
			}
		}
		else 
		{
			// TODO file does not exist
		}

		rfsFile.close();
	}

	
	// TODO return boolean or exception handling?
	return true;

}

void ConstructAndAddUser(string strLine, TextFileDataSource* tfds)
{
	DataMap* pdmUsers = tfds->getUsersCollection();
	vector<string> vecstrLineSplit = StringUtils::splitString(strLine, ',');

	int nUserID = TypeConverter(vecstrLineSplit[TextFileDataSource::USER_NAME]);
	string strPassword = vecstrLineSplit[TextFileDataSource::PASSWORD];
	int nUserType = TypeConverter(vecstrLineSplit[TextFileDataSource::USER_TYPE]);

	if (nUserType == User::CUSTOMER)
	{
		// TODO ASSERTS HERE
		string strName = vecstrLineSplit[TextFileDataSource::NAME];
		string strAddress = vecstrLineSplit[TextFileDataSource::ADDRESS];
		string strPhone = vecstrLineSplit[TextFileDataSource::PHONE_NUMBER];

		Customer* pu = new Customer(nUserID, strPassword, strName, strAddress, strPhone); 
	

		// add accoutn ids
		vector<string> vecstrAccountIds = StringUtils::splitString(vecstrLineSplit[TextFileDataSource::ACCOUNT_IDS],';');
		for (unsigned nId = 0; nId < vecstrAccountIds.size(); nId++)
		{
			pu->addAccount(TypeConverter(vecstrAccountIds[nId]));
		}

		pdmUsers->Add(pu);

	}
	else if (nUserType == User::BANK_CLERK)
	{
		pdmUsers->Add
			(
				new BankClerk(nUserID, strPassword)	
			);
	}

}

void ConstructAndAddAccount(string strLine, TextFileDataSource* tfds)
{
}

void ConstructAndAddTransaction(string strLine, TextFileDataSource* tfds)
{
}

void ReadAndSetLastUserId(string strLine, TextFileDataSource* tfds)
{
}




// --------------------------------------------------------------------------------------------- //


