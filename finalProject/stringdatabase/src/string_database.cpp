#include "../includes/string_database.h"
using namespace std;

String_Database::String_Database(void) {

}
String_Database::~String_Database(void) {

}
//if not seen yet then add myString to myStrings
//otherwise increment the count for myString
void String_Database::add(std::string &myString) {
		lock_guard<std::mutex> m(mutex);
	for(myStringsIter = myStrings.begin(); myStringsIter != myStrings.end();myStringsIter++){
		if (*myStringsIter == myString) {
			myStringsIter->increment();
			return;
		}
	}
	myStrings.push_back(myString);
	return;
}

//get number of times myString has been seen (or added with add)
int String_Database::getCount(std::string &myString) {
	for (String_Data s : myStrings) {
		lock_guard<std::mutex> m(mutex);
		if (s.operator ==(myString)) {
			return s.getCount();
		}
	}
	return 0;
}

//clear the myStrings vector
void String_Database::clear() {
	lock_guard<std::mutex> m(mutex);
	myStrings.clear();

}

//load from datastore, returns
//false if myDataStore = 0
//otherwise returns myDataStore->load results
bool String_Database::load(DataStore *myDataStore) {
	if(!myDataStore){
		return false;
	}
//	lock_guard<std::mutex> m(mutex);
	return myDataStore->load(myStrings);
}

//save to datastore,returns
//false if myDataStore = 0
//otherwise returns myDataStore->save results
bool String_Database::save(DataStore *myDataStore) {
	if(!myDataStore){
		return false;
	}
//	lock_guard<std::mutex> m(mutex);
	return myDataStore->save(myStrings);
}
