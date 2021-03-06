/*
 * tester.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: waida
 */

#include "tester.h"
#include "print_ts.h"
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include<iostream>
using namespace std;
int numThread=0;
int isCancel = 0;
mutex n;
std::vector<thread> v;
void multiprint(std::string s, WHICH_PRINT wp, int numTimesToPrint,
		int millisecond_delay) {
	std::thread::id this_id = std::this_thread::get_id();
	for (int i = 0; i < numTimesToPrint; i++) {
		if (isCancel == 0) {
			switch (wp) {
			case (P1):
						PRINT1(s);
			break;
			case (P2):
						PRINT2(s, s);
			break;

			case (P3):
						PRINT3(s, s, s);
			break;

			case (P4):
						PRINT4(s, s, s, s);
			break;

			case (P5):
						PRINT5(s, s, s, s, s);
			break;
			}
			std::this_thread::sleep_for(
					std::chrono::milliseconds(millisecond_delay));
		}
		else{
			break;
		}
	}
	if (isCancel == 1) {
		n.lock();
		cout << USER_CHOSE_TO_CANCEL << endl;
		std::cout << "Thread: " << this_id << " exiting" << std::endl;
		n.unlock();
	}
	if (isCancel == 2) {
		n.lock();
		cout << "USER CHOSE TO RESET LOGIC" << endl;
		std::cout << "Thread:" << this_id << " exiting" << std::endl;
		n.unlock();
	}

}

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 *
 * if user chooses to cancel then this function should print USER_CHOSE_TO_CANCEL before exit
 */
void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay) {
	isCancel = 0;
	for (int i = 0; i < numThreads; ++i) {
		v.push_back(
				std::thread(multiprint, s, wp, numTimesToPrint,
						millisecond_delay));
	}
}

/*
 * if bCanceled== true then causes all running threads to exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {
	if (bCancel) {
		isCancel = 1;
		joinThreads();
	} else {
		isCancel = 2;
		joinThreads();
		isCancel = 0;
		numThread = 0;
	}
}

/*
 * waits for all threads to complete
 */
void joinThreads() {
	for (auto& thread : v) {
		thread.join();
	}

}

