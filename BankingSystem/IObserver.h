#pragma once
class IObserver
{
public:

	virtual void update() = 0;

};

class Observer : public IObserver
{

public:

	virtual void update();

private:


}

