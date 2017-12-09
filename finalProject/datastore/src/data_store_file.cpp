#include "../includes/data_store_file.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//pass in a crypto object and it will be used to en/decrypt data
//don't, and data stored in clear
DataStore_File::DataStore_File(std::string fileName, Crypto* crypto) :
				DataStore::DataStore(crypto),myFileName(fileName) {

}

DataStore_File::~DataStore_File(void) {

}

//load from file myFileName, if present, use the crypto object to decrypt
bool DataStore_File::load(std::vector<String_Data> &myVector) {
	ifstream myfile;
	myfile.open(myFileName.c_str());
	if (myfile.is_open()) {
		string data;
		int useCount;
		bool p;
		std::string line;
		while (std::getline(myfile, line)) {
			DataStore::decrypt(line);
			string &myString = line;	//serial code
			String_Data *sData;
			p = sData->parseData(myString, data, useCount);
//			delete sData;
			String_Data *s = new String_Data(data,useCount);
			myVector.push_back(*s);
			delete s;

		}
		return p;
	}
	return false;
}

//save to file myFileName, if present, use the crypto object to encrypt
//I extracted one entry of the vector at a time and then encrypted it
//if crypto object present, saved this to disk and then sent a std::endl
//so each entry is encrypted, but you can count the number of entries
//by the number of lines in the file
bool DataStore_File::save(std::vector<String_Data> &myVector) {
	ofstream myfile;
	myfile.open(myFileName.c_str());
	if (myfile.is_open()) {
		for (String_Data data : myVector) {
			std::string s = data.serialize();
			std::string &myString = s;
			DataStore::encrypt(myString);
			myfile << myString << endl;
		}
		myfile.close();
		return true;
	}
	return false;
}

bool DataStore_File::openFile(std::fstream& myfile,
		const std::string& myFileName, std::ios_base::openmode mode) {
	myfile.open(myFileName.c_str());
	if (myfile.is_open()) {
		return true;
	} else {
		return false;
	}
}

void DataStore_File::closeFile(std::fstream& myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}
