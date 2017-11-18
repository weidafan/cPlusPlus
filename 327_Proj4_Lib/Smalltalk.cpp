/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: waida
 */
#include "includes/Smalltalk.h"
#include <string>
#include <iostream>
#include "includes/constants.h"
//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish objects of the same type
Smalltalk::Smalltalk(std::string myNationality, int iPerson) :
	nationality(myNationality),iPerson(iPerson),pWatch(0),current_phrase(iPerson) {

}
//if pWatch !=0 then be sure to delete the pointer
Smalltalk::~Smalltalk(void) {
	if (pWatch)
		delete pWatch;
}
//cycles through and returns phrases created in populatePhrases
//takes the form Nationality iPerson: phrase
//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
//AMERICAN 10:Why yes, I would like to supersize that
std::string Smalltalk::saySomething() {
	return nationality ;//+ " " + iPerson + ":"; //+ mySmallTalk[current_phrase-1];
//	if (nationality == AMERICAN) {
//		if (iPerson <= 5)
//			current_phrase = iPerson;
//		else
//			current_phrase = iPerson % 5;
//		switch (current_phrase) {
//		case 1:
//			return AMERICAN_PHRASE_1;
//		case 2:
//			return AMERICAN_PHRASE_2;
//		case 3:
//			return AMERICAN_PHRASE_3;
//		case 4:
//			return AMERICAN_PHRASE_4;
//		case 5:
//			return AMERICAN_PHRASE_5;
//		default:
//			std::cout << "wrong input\n";
//			break;
//		}
//	}
//	if (nationality == BRIT) {
//		if (iPerson <= 5)
//			current_phrase = iPerson;
//		else
//			current_phrase = iPerson % 5;
//		switch (current_phrase) {
//		case 1:
//			return BRIT_1;
//		case 2:
//			return BRIT_2;
//		case 3:
//			return BRIT_3;
//		case 4:
//			return BRIT_4;
//		case 5:
//			return BRIT_5;
//		case 6:
//			return BRIT_6;
//		case 7:
//			return BRIT_7;
//		default:
//			std::cout << "wrong input\n";
//			break;
//		}
//	}
//	if (nationality == AMERICAN_DE) {
//		if (iPerson <= 7)
//			current_phrase = iPerson;
//		else
//			current_phrase = iPerson % 7;
//		switch (current_phrase) {
//		case 1:
//			return AMERICAN_DE_PHRASE_1;
//		case 2:
//			return AMERICAN_DE_PHRASE_2;
//		case 3:
//			return AMERICAN_DE_PHRASE_3;
//		case 4:
//			return AMERICAN_DE_PHRASE_4;
//		case 5:
//			return AMERICAN_DE_PHRASE_5;
//		default:
//			std::cout << "wrong input\n";
//			break;
//		}
//	}
//	return "";
}
//returns the time or I_DO_NOT_HAVE_A_WATCH string
std::string Smalltalk::getTime() {
	if (!pWatch) {
		return I_DO_NOT_HAVE_A_WATCH;
	} else {
		return pWatch->getTime();
	}
}
//if this object has a watch it is taken away,
//this means return the pointer and set this->pWatch =NULL;
Watch * Smalltalk::takeWatch() {
	if (pWatch)
		this->pWatch = 0;
	return pWatch;
}
//if already have a watch then return false and dont change pWatch pointer
//otherwise accept watch (return true) and set this->pWatch=pWatch
bool Smalltalk::giveWatch(Watch *pWatch) {
	if (this->pWatch) {
		return false;
	} else {
		this->pWatch = pWatch;
		return true;
	}
}

