
#ifndef _TRANSACTION_H
#define _TRANSACTION_H
#include <string>

#include "date.h"

class Transaction
{
public:
	
	Transaction (int id, double amount, int customerId, std::string dt)
	{
		_id = id; _amount = amount; _customerId = customerId; _date = dt;
	}

	virtual void execute(){};

	int getId(){return _id;}
	double getAmount(){return _amount;}
	int getCustomerId(){return _customerId;}
	std::string getDate(){return _date;}

private:

	int _id;
	double _amount;
	int _customerId;
	std::string _date;

};

#endif
