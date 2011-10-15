#pragma once
#include "Transaction.h"

class Deposit : public Transaction
{
public:

	Deposit(Identifier<int> id, double amount, int customerId, date dt, int accountId);
	
	virtual void execute();

private:

	int _accountId;

};

