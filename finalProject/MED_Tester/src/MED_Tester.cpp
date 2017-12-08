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
mutex m1;

bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2,
		Crypto *pCrypto) {
	DataStore_File myDataStore_File1(MYFILE1, pCrypto);
	lock_guard<mutex> m(m1);
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
	std::cout<<"Saving to file "+ MYFILE2 +" \n";

	//I use my own objects here to compare the files
	return true;
}

int main() {
		char key[] = "I Like Rollos   ";
		char *pKey = &key[0];
		Crypto *myCrypto = new Crypto_AES(pKey);
		std::string str1 = "this string";
		myGlobalCache.add(str1);
		testSerialization("MYFILE1","MYFILE2",myCrypto);
		testSerialization("MYFILE1","MYFILE2",0);

		delete myCrypto;
//		thread t1(testSerialization,"MYFILE1","MYFILE2",&myCrypto); 	//f1 - 2 threads
//		thread t2(f1);
//		thread t3(f2);	//f2 - 2 threads
//		thread t4(f2);
//		thread t5(f3);	//f3 - 2 threads
//		thread t6(f3);

	//	thread t7(f1); 	//f1 - 3 threads
	//	thread t8(f2);	//f2 - 3 threads
	//	thread t9(f3);	//f3 - 3 threads

		//delay long enough for threads to start and get some work done
		std::this_thread::sleep_for(std::chrono::microseconds(1000000)); //add a 0 to examine system monitor resources view

		//t1.join();
//		t2.join();
//		t3.join();
//		t4.join();
//		t5.join();
//		t6.join();
	//	t7.join();
	//	t8.join();
	//	t9.join();
	//I created and ran a bunch(20) of threads that added different strings to a string_database instance
//	std::vector<thread> myThreads;
//	Crypto *pCrypto = new Crypto_AES("I Like Rollos   ");
//	for (int i = 0; i < 20; ++i) {
//		myThreads.push_back(std::thread(testSerialization,"MYFILE1","MYFILE2"));
}
	//Then I waited for all of them to finish so my program did not crash

	//Then I went through my string_database instance and made sure that it held the correct data

	//then I tested  serialization
	//first without encryption,
	//testSerialization(NO_ENCRYPT_FILE1, NO_ENCRYPT_FILE2, 0);

	//then with
	//Crypto_AES myCrypto("I Like Rollos   ");
	//testSerialization(ENCRYPT_FILE1, ENCRYPT_FILE2, &myCrypto);

