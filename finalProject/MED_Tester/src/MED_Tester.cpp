//============================================================================
// Name        : MED_Tester.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <sstream>
#include "../../datastore/includes/data_store.h"
#include "../../crypto/includes/crypto.h"
#include "../../stringdatabase/includes/string_database.h"
#include "../../crypto/includes/crypto_AES.h"

using namespace std;

//I've provided some hints in the form of comments and commented out code
//use them if you wish

////global database object 
String_Database myGlobalCache;

bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2,
		Crypto *pCrypto) {
	DataStore_File myDataStore_File1(MYFILE1, pCrypto);

	myGlobalCache.save(&myDataStore_File1);

	//	//clear cache
	myGlobalCache.clear();
	std::cout << "Clearing Cache\n";
	//
	//	//load it
	myGlobalCache.load(&myDataStore_File1);
	std::cout << "Loading from file " + MYFILE1 + " \n";

	//	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2, pCrypto);
	myGlobalCache.save(&myDataStore_File2);
	std::cout << "Saving to file " + MYFILE2 + " \n";

	//I use my own objects here to compare the files
	return true;
}

int main() {
	std::vector<thread> mythreads;
//	I created and ran a bunch(20) of threads that added different strings to a string_database instance
	for (int i = 0; i < 50; i++) {
		string s = "bear" + to_string(i);
		mythreads.push_back(
				std::thread(&String_Database::add, &myGlobalCache, ref(s)));
	}

	//Then I waited for all of them to finish so my program did not crash
	for (auto & thread : mythreads) {
		thread.join();
	}

	//Then I went through my string_database instance and made sure that it held the correct data
	string bear = "bear1";
	std::cout << myGlobalCache.getCount(bear) << endl;

//	//then I tested  serialization
//	//first without encryption,
	testSerialization("NO_ENCRYPT_FILE1", "NO_ENCRYPT_FILE2", 0);

//	//then with
	Crypto_AES myCrypto("I Like Rollos   ");
	testSerialization("ENCRYPT_FILE1", "ENCRYPT_FILE2", &myCrypto);

	//Test with different amount of animals.
//		myGlobalCache.clear();
		string str1 = "pig";
		string str2 = "pig";
		string str3 = "dog";
		string str4 = "cat";
		string str5 = "dog";
		string str6 = "cat";
		string str7 = "fish";
		string str8 = "dog";

		thread t1(&String_Database::add,&myGlobalCache,ref(str1));
		thread t2(&String_Database::add,&myGlobalCache,ref(str2));
		thread t3(&String_Database::add,&myGlobalCache,ref(str3));
		thread t4(&String_Database::add,&myGlobalCache,ref(str4));
		thread t5(&String_Database::add,&myGlobalCache,ref(str5));
		thread t6(&String_Database::add,&myGlobalCache,ref(str6));
		thread t7(&String_Database::add,&myGlobalCache,ref(str7));
		thread t8(&String_Database::add,&myGlobalCache,ref(str8));


		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();

		testSerialization("NO_ENCRYPT_FILE1", "NO_ENCRYPT_FILE2", 0);
		testSerialization("ENCRYPT_FILE1", "ENCRYPT_FILE2", &myCrypto);

}

