/*
 * main.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: waida
 */
#include "tester.h"
#include <string>
#include <chrono>
#include<thread>
#include<iostream>
using namespace std;
int main() {
	string s = "hello world!!!!";
	int numThreads = 10000;
	WHICH_PRINT wp = P1;
	int numTimesToPrint = 4;
	int millisecond_delay = 1000;
	startThreads(s, numThreads, wp, numTimesToPrint, millisecond_delay);
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	setCancelThreads(true);

	cout << "All threads done!" << endl;
	return 0;
}

