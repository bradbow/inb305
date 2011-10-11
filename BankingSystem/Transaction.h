
#ifndef _TRANSACTION_H
#define _TRANSACTION_H

class Transaction
{
public:
	Transaction(float amount);
	~Transaction(void);

	float getAmount();

private:
	float _amount;
};

#endif
