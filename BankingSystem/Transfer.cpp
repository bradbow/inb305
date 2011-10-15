#include "Transfer.h"

Transfer::Transfer
(
	Identifier<int> id, double amount, int customerId, 
	date dt, int toAccId, int fromAccId
) : Transaction(id, amount, customerId, dt)
{
	
	_toAccId = toAccId;
	_fromAccId = fromAccId;

}

void Transfer::execute()
{



}


