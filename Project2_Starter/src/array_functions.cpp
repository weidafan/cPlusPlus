/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */
//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.h"
#include "utilities.h"
#include "array_functions.h"
#include <algorithm>
//============================================================================
//	stuff you will need
//============================================================================
using namespace std;
using namespace constants;
//TODO define a structure to track words and number of times they occur
struct entry {
	string word;
	int number_occurences;
};
int array_size = 0;
//TODO add a global array of entry structs (global to this file)
entry myEntryArray[MAX_WORDS];

//TODO add variable to keep track of next available slot in array
int next_slot = 0;

//TODO define all functions in header file

//zero out array that tracks words and their occurrences
void clearArray() {
	array_size = 0;
	next_slot = 0;
}

//how many unique words are in array
int getArraySize() {
	return array_size;
}

//get data at a particular location
std::string getArrayWordAt(int i) {
	return myEntryArray[i].word;
}
int getArrayWord_NumbOccur_At(int i) {
	return myEntryArray[i].number_occurences;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream) {
	if (myfstream.is_open()) {
		std::string line;
		while (std::getline(myfstream, line)) {
			processLine(line);
		}
		return true;
	} else {
		return false;
	}
}

/*take 1 line and extract all the tokens from it
 feed each token to processToken for recording*/
void processLine(std::string &myString) {
	stringstream ss(myString);
	string tempToken;
	while (getline(ss, tempToken, CHAR_TO_SEARCH_FOR)) {
		processToken(tempToken);
	}
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token) {
	strip_unwanted_chars(token);
	//cout << token;
	string s = token;
	toUpper(s);
	if (token != "") {
		for (int j = 0; j < array_size; j++) {
			string c = myEntryArray[j].word;
			toUpper(c);
			if (s == c) {
				(myEntryArray[j].number_occurences)++;
				return;
			}

		}
		myEntryArray[next_slot].word = token;
		myEntryArray[next_slot].number_occurences = 1;
		next_slot++;
		array_size++;
	}
}

/*if you are debugging the file must be in the project parent directory
 in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode /*= std::ios_base::in*/) {
	myfile.open(myFileName.c_str());
	if (myfile.is_open()) {
		return true;
	} else {
		return false;
	}
}

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename) {
	ofstream myfile;
	myfile.open(outputfilename.c_str());
	//ofstream myfile(outputfilename);
	if (myfile.is_open() == false) {
		return FAIL_FILE_DID_NOT_OPEN;
	} else if (array_size == 0) {
		myfile.close();
		return FAIL_NO_ARRAY_DATA;
	}

	else {
		for (int i = 0; i < array_size; i++) {
			cout << myEntryArray[i].word << " "
					<< myEntryArray[i].number_occurences << endl;
			myfile << myEntryArray[i].word << " "
					<< myEntryArray[i].number_occurences << endl;
		}
		myfile.close();
		return SUCCESS;
	}
}
bool compareName(entry &x, entry &y) {
	string a = x.word;
	string b = y.word;
	toUpper(a);
	toUpper(b);
	return a < b;
}
/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 * You are provided with a myentry compare function in the cpp file
 */
void sortArray(constants::sortOrder so) {

	if (so == ASCENDING) {
		std::sort(myEntryArray, myEntryArray + array_size, compareName);
	}
}
