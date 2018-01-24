/*
 * main.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: waida
 */
#include "utilities.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(){
	//see if we can open, process, sort, and write the file back to disk
	int i = loadData("TestData.txt");
	if(i == SUCCESS){
		cout<<"load SUCCESS"<<endl;
	}
	//		sortData(CPU_TIME);
	sortData(PROCESS_NUMBER);
	//		sortData(START_TIME);
	int s = saveData("SaveData.txt");
	if(s == SUCCESS){
		cout<<"save success"<<endl;
	}
	ifstream myfile;
	myfile.open("TestData.txt");
	if (myfile.is_open()) {
	while(!myfile.eof()){
		process_stats g = getNext();
		cout<<g.process_number<<","<<g.start_time<<","<<g.cpu_time<<endl;
	}
	}
}



