#include "Transaction.h"


Transaction::Transaction(float amount) : _amount(amount)
{

}


Transaction::~Transaction(void)
{
}

float Transaction::getAmount(){

	return this->_amount;
}
