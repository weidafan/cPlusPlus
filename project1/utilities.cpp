/*
 * utilities.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: waida
 */

#include "utilities.h"
#include <fstream>
#include <sstream>
#include<vector>
#include <algorithm>
using namespace std;
//allthe functions available for use
vector<process_stats> myVector;

//clears vector holding process_stats structs
//attempt to open file 'filename' to read, parse its rows
//into process_stats structs and add these structs to a vector
//
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int loadData(const char* filename) {
	myVector.clear();
	ifstream myfile;
	myfile.open(filename);
	if (myfile.is_open()) {
		string line;
		vector<int> v;
		while (!myfile.eof()) {
			getline(myfile, line);
			stringstream ss(line);
			string tempToken;
			while (getline(ss, tempToken, CHAR_TO_SEARCH_FOR)) {
				stringstream geek(tempToken);
				int x;
				geek >> x;
				v.push_back(x);
			}
			process_stats temp;
			temp.process_number = v[0];
			temp.start_time = v[1];
			temp.cpu_time = v[2];
			myVector.push_back(temp);
			v.clear();
		}
		myfile.close();
		return SUCCESS;
	} else {
		return COULD_NOT_OPEN_FILE;
	}
}

//attempt to open file 'filename' to write, and serialize a
//vector full of process_stats structs to it.  Should be in the same
//format as original file but not necessarily the same order or length
//if the file exists, overwrite its contents.
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int saveData(const char* filename) {
	ofstream outfile;
	outfile.open(filename);
	if (outfile.is_open()) {
		for (process_stats s : myVector) {
			outfile << s.process_number << "," << s.start_time << ","
					<< s.cpu_time << endl;
		}
		outfile.close();
		return SUCCESS;
	} else
		return COULD_NOT_OPEN_FILE;
}
bool CPU_Cmp(process_stats const & a, process_stats const & b) {
	return a.cpu_time < b.cpu_time;
}
bool process_number_Cmp(process_stats const & a, process_stats const & b) {
	return a.process_number < b.process_number;
}
bool start_time_Cmp(process_stats const & a, process_stats const & b) {
	return a.start_time < b.start_time;
}
//sorts the vector, returns nothing (thats what void means)
//sorts low to high
void sortData(SORT_ORDER mySortOrder) {
	if (mySortOrder == CPU_TIME) {
		sort(myVector.begin(), myVector.end(), CPU_Cmp);
	} else if (mySortOrder == PROCESS_NUMBER) {
		sort(myVector.begin(), myVector.end(), process_number_Cmp);
	} else {
		sort(myVector.begin(), myVector.end(), start_time_Cmp);
	}
}

//return the first struct in the vector
//then deletes it from the vector
process_stats getNext() {
	process_stats temp = myVector[0];
	if (myVector.begin() != myVector.end()) {
		myVector.erase(myVector.begin());
	}
	return temp;
}
