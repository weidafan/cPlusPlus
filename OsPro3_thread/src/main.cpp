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
	int numThreads = 1;
	WHICH_PRINT wp = P1;
	int numTimesToPrint = 1;
	int millisecond_delay = 100;
	startThreads(s, numThreads, wp, numTimesToPrint, millisecond_delay);
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	setCancelThreads(false);
	cout << "All threads done!" << endl;
	return 0;
}
