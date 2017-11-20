// smalltalk_VirtualAbstractVector.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include "../../327_Proj4_Lib/includes/Smalltalk.h"
#include "../../327_Proj4_Lib/includes/Functions.h"
#include "../../327_Proj4_Lib/includes/Smalltalk_Brit.h"
#define NDEBUG
#include <assert.h> /* assert */
// make sure you have the right number of watches
// make sure you consider the case where you have more watches than people
//int num_watch(int numBrit, int American, int A_donut, int numWatches) {
//	std::vector<std::unique_ptr<Smalltalk> > myv1 = getPeople(numBrit, American,
//			A_donut, numWatches);
//	int count = numWatches;
//	for (int i = 0; i < numWatches; i++) {
//		Watch * watch = new Watch();
//		if (myv1[i]->giveWatch(watch)) {
//			count--;
//		}
//		delete watch;
//	}
//	return count;
//}

//TODO make sure you do not do a deep copy any watches when giving or taking them
//     the simplest way is give and take the watch a few times and verify that the old recipients have
//     a null pWatch pointer
//     and that the pointer returned from the last takeWatch is the same as the one you began with on giveWatch
//Watch * p(Watch * watch){
//	Smalltalk_Brit *bri = new Smalltalk_Brit(1);
//	bri->giveWatch(watch);
//	bri->takeWatch();
//	delete bri;
//	return watch;
//}
//TODO make sure saySomething() cycles through appropriate phrases

void demo() {
	int numEachGroup = 10;
	int numwatches = 3;

	std::vector<std::unique_ptr<Smalltalk> > myv1 = getPeople(numEachGroup,
			numEachGroup, numEachGroup, numwatches);
	for (unsigned int i = 0; i < myv1.size(); i++) {
		std::cout << myv1[i]->saySomething() << std::endl;
		std::cout << myv1[i]->getTime() << std::endl;
	}
	for (unsigned int i = 0; i < myv1.size(); i++) {
		myv1[i]->takeWatch();
	}
}
int main() {
	demo();
//   int real = num_watch(2,3,3,4);
//	int expect = 4;
//	assert( real != expect && "watch number not match");
//	std::cout << "tested watch < num of people: number of watch check + 1 point"<< std::endl;
//	real = num_watch(2,1,1,6);
//	expect = 4;
//	assert(real == expect && "watch number not match" );
//	std::cout << "tested watch > num of people: number of watch check + 2 point"<< std::endl;
//	Watch * watch = new Watch();
//	assert(p(watch)==0 && "This is deep copy, we need shallow copy");
//	std::cout << "tested watch is not deep copy + 3 point"<< std::endl;

	//the above call produces the following console output

	//	BRIT 0:Im a bit knackered mate
	//	BRIT 0:The time is: 27 minutes after1
	//	BRIT 1:Im a bit knackered mate
	//	BRIT 1:The time is: 27 minutes after1
	//	AMERICAN 0:Why yes, I would like to supersize that
	//	AMERICAN 0:I do not have a watch
	//	AMERICAN 1:Why yes, I would like to supersize that
	//	AMERICAN 1:I do not have a watch
	//	AMERICAN_DONUT_ENTHUSIEST 0:Dunkin Donuts is a horrendous, disappointing compromise
	//	AMERICAN_DONUT_ENTHUSIEST 0:I do not have a watch`
	//	AMERICAN_DONUT_ENTHUSIEST 1:Dunkin Donuts is a horrendous, disappointing compromise
	//	AMERICAN_DONUT_ENTHUSIEST 1:I do not have a watch

}
