#pragma once
#include "Transaction.h"
#include <string>
using namespace std;

class Withdrawal : public Transaction
{
public:

	Withdrawal(int id, double amount, int customerId, std::string dt, int accountId);
	virtual void execute();

private:

	int _accountId;

};

