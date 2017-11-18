/*
 * ST_American_DonutEnthusiest.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: waida
 */
#include "includes/ST_American_DonutEnthusiest.h"
#include "includes/constants.h"

ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int iPerson) :
		Smalltalk_American::Smalltalk_American(AMERICAN_DE, iPerson) {
	ST_American_DonutEnthusiest::populatePhrases();
}
ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest(void) {
	if (pWatch)
		delete pWatch;
}
void ST_American_DonutEnthusiest::populatePhrases() {
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}

