
#ifndef _TRANSACTION_H
#define _TRANSACTION_H
#include <string>
#include "AccountServices.h"

//#include "date.h"
#include <boost\date_time\gregorian\gregorian.hpp>

using namespace boost::gregorian;

class Transaction
{
public:
	
	Transaction (int id, double amount, int customerId, date dt)
	{
		_id = id; 
		_amount = amount; 
		_customerId = customerId; 
		_date = dt;
	}

	virtual void execute(){}

	int getId(){return _id;}
	double getAmount(){return _amount;}
	int getCustomerId(){return _customerId;}
	date getDate(){return _date;}

protected:

	int _id;
	double _amount;
	int _customerId;
	date _date;

};

#endif
