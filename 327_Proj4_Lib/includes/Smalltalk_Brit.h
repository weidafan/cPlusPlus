#pragma once
#include "Smalltalk.h"

class Smalltalk_Brit :
	public Smalltalk
{
public:
	Smalltalk_Brit(int iPerson=1);
	virtual ~Smalltalk_Brit(void);
	virtual void populatePhrases(); 
};

