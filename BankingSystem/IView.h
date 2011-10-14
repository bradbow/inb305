#pragma once
class IView: public IObserver, ISubject
{
public:
	
	virtual void intitialise() = 0;
	virtual void repaint() = 0;

};

