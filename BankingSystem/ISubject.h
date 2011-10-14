#pragma once
class ISubject
{
public:

	virtual void notify() = 0;
	virtual void attachObserver() = 0;
	virtual void removeObserver() = 0;

};

