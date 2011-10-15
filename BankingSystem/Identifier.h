#pragma once
#include <string>

template <class I>
class Identifier
{
public:
	
	Identifier(){}
	Identifier(I id){_id = id;}
	I getId(){return _id;}

private:

	I _id;

};

