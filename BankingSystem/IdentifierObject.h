#pragma once
#include "Identifier.h"

template<class I>
class IdentifierObject
{
public:

	IdentifierObject(Identifier<I> identifer){_identifier = identifer;}
	Identifier<I> getIdentifier(){return _identifier;}

private: 
	
	Identifier<I> _identifier;

};

