#pragma once
#include "IModel.h"
#include "IView.h"
#include "ISubject.h"
#include "IObserver.h"
#include <vector>

class IController : public IObserver, ISubject
{
public:
	
	virtual void notify() = 0;
	virtual void launch() = 0;
	virtual void close() = 0;

};

class Controller : public IController
{

	virtual void notify()
	{
		std::vector<IObserver>::iterator vit;
		for (vit = _observers.begin(); vit != _observers.end(); ++vit)
		{
			*(vit)
		}
	}

private:

	std::vector<IObserver> _observers;
	//View _view;
	//Model _model;
	

};

