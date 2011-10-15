#pragma once
#include "Transaction.h"
#include <string>
using namespace std;

class Transfer : public Transaction
{
public:
	
	Transfer(int id, double amount, int customerId, date dt, int toAccId, int fromAccId);
	virtual void execute();

private:

	int _toAccId;
	int _fromAccId;

};

