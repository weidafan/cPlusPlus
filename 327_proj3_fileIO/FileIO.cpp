/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream myfile;
	myfile.open(filename.c_str());
	//TODO fill in
	if(myfile.is_open()){
		string line;
		while(!myfile.eof()){
			getline(myfile,line);
			contents.append(line);
		}
		myfile.close();
		return SUCCESS;
	}
	else{
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outfile;
	outfile.open(filename.c_str());
	if(outfile.is_open()){
		for(string s: myEntryVector){
			outfile<<s<<endl;
		}
		outfile.close();
		return SUCCESS;
	}
	else
		return COULD_NOT_OPEN_FILE_TO_WRITE;
}

