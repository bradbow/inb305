#pragma once
#include "Transaction.h"
#include <string>
using namespace std;

class Withdrawal : public Transaction
{
public:

	Withdrawal(Identifier<int> id, double amount, int customerId, date dt, int accountId);
	virtual void execute();

private:

	int _accountId;

};

