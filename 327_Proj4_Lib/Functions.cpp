/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

//create a vector with a brit,american, donut enthusiest using unique pointers
//use c++11 and then returning by value is fine since the compiler will move the vector
//on return rather than recreate it(if using C++11).
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	int total = numBrit + numAmerican + numbAmericanDonutEnthusiest;
	//create a vector to hold SmallTalk unique pointers
	std::vector<std::unique_ptr<Smalltalk>> temp;
	//add brits to vector
	for(int i = 1; i < numBrit+1; i++){
		temp.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_Brit(i)));
	}
	//add americans  to vector
	for(int i = 1; i <numAmerican +1; i++){
		temp.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_American(i)));
	}
	//add american donut enthusiest  to vector
	for(int i = 1; i <numbAmericanDonutEnthusiest +1; i++){
		temp.push_back(std::unique_ptr<Smalltalk>(new ST_American_DonutEnthusiest(i)));
	}
	//create some watches (as long as number watches <= numb people)	
	//then give the watches away to first NUM_WATCHES people in the vector
	//keep in mind that you are responsible for deleting any pointers to 
	//watches allocated on the heap when you are finished using the vector you return 
	//from this function(see Smalltalk header for hints)
	//return your vector
	if(numWatches<= total){
		for(int i = 0; i < numWatches; i++){
			Watch * watch = new Watch();
			if(!temp[i]->giveWatch(watch)){
				delete watch;
			}
		}
	}
	return temp;
}
