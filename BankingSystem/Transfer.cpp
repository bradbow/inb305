#include "Transfer.h"

Transfer::Transfer
(
	int id, double amount, int customerId, 
	std::string dt, int toAccId, int fromAccId
) : Transaction(id, amount, customerId, dt)
{
	
	_toAccId = toAccId;
	_fromAccId = fromAccId;

}

void Transfer::execute()
{



}


