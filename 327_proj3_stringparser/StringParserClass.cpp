/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"
using namespace KP_StringParserClass;
using namespace std;
StringParserClass::StringParserClass(void) :
		pStartTag(0), pEndTag(0), areTagsSet(false) {

}
StringParserClass::~StringParserClass(void) {
	cleanup();
}

void StringParserClass::cleanup() {
	if (pStartTag) {
		delete[] pStartTag;
	}
	if (pEndTag) {
		delete[] pEndTag;
	}

}
int StringParserClass::findTag(char *pTagToLookFor, char *&pStart,
		char *&pEnd) {
	int len_start = strlen(pStart);
	int len_tag = strlen(pTagToLookFor);
	char *temp = pTagToLookFor;
	char *pStart_temp = pStart;
	bool find_start = false;
	int count = 0;
	for (int i = 0; i < len_start; i++) {
		if (*pStart_temp != *temp) {
			pStart_temp++;
			count = 0;
			temp = pTagToLookFor;
			continue;
		}
		count++;
		if (count == len_tag) {
			find_start = true;
			pStart = pStart + (i - len_tag + 1);
			break;
		}
		pStart_temp++;
		temp++;
	}
	int len2 = strlen(pStart_temp);
	char *temp_end = pEndTag;
	pEnd = pStart_temp;
	for (int i = 0; i < len2; i++) {
		if (*pStart_temp != *temp_end) {
			pStart_temp++;
			count = 0;
			temp_end = pEndTag;
			continue;
		}
		count++;
		if (count == (len_tag + 1) && find_start) {
			pEnd += i-len_tag;
			return SUCCESS;
		}
		pStart_temp++;
		temp_end++;
	}
	pEnd = 0;
	return FAIL;
}

int StringParserClass::setTags(const char *pStart, const char *pEnd) {
	if (!pStart || !pEnd) {
		return ERROR_TAGS_NULL;
	}
	int len = strlen(pStart) + 1;
	pStartTag = new char[len];
	strcpy(pStartTag, pStart);
	len = strlen(pEnd) + 1;
	pEndTag = new char[len];
	strcpy(pEndTag, pEnd);
	return SUCCESS;
}

int StringParserClass::getDataBetweenTags(char *pDataToSearchThru,
		std::vector<std::string> &myVector) {
	myVector.clear();
	if(!pStartTag || !pEndTag){
		return ERROR_TAGS_NULL;
	}
	if(!pDataToSearchThru){
		return ERROR_DATA_NULL;
	}
	char *temp= pStartTag;
	char * temp_end = pEndTag;
	int len = strlen(pStartTag);
	int find = findTag(pStartTag,pDataToSearchThru,temp_end);
		pDataToSearchThru += len;
	while(find == SUCCESS){
	string data = "";
		while(pDataToSearchThru!= temp_end){
			data+=*pDataToSearchThru;
			pDataToSearchThru++;
		}
		myVector.push_back(data);
		find = findTag(pStartTag,pDataToSearchThru,temp_end);
		pDataToSearchThru += len;

	}
	return SUCCESS;
}

