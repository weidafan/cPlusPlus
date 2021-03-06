/*
 * Smalltalk_American.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: waida
 */
#include "includes/Smalltalk_American.h"
#include "includes/constants.h"
	//use base class call to set Nationality (See constants for Nationality strings)
	Smalltalk_American::Smalltalk_American(int iPerson):Smalltalk::Smalltalk(AMERICAN,iPerson){
		Smalltalk_American::populatePhrases();
	}
	Smalltalk_American::Smalltalk_American(std::string myNationality,int iPerson):Smalltalk::Smalltalk(myNationality,iPerson){

	}
	Smalltalk_American::~Smalltalk_American(void){
		if(pWatch)
			delete pWatch;
	}
	void Smalltalk_American::populatePhrases(){
		mySmallTalk.push_back(AMERICAN_PHRASE_1);
		mySmallTalk.push_back(AMERICAN_PHRASE_2);
		mySmallTalk.push_back(AMERICAN_PHRASE_3);
		mySmallTalk.push_back(AMERICAN_PHRASE_4);
		mySmallTalk.push_back(AMERICAN_PHRASE_5);
	}



