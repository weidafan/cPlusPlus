/*
 * main.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: keith
 */
// object demo.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <iostream>
#include <string.h>
#include "Flower.h"

using namespace std;

void pointers_warmup()
{
	int x = 3;
	int y = 10;
	int *z = &x;
	z = &y;
	cout << "z points to " << *z << endl;

	z = &x;
	*z = 14;
	cout << "x is " << x << endl;
	z = &x;
	x = y;
	cout << "z points to " << *z << endl;

	*z = 28;
	cout << "z points to " << *z << endl;

	int b[2] = { 1, 2 };
	z = b;
	cout << "*b points to " << *b << endl;
	cout << "z+1 points to " << *(z + 1) << endl;

	int* a = new int(37);
	z = a;
	cout << "z points to " << *z << endl;
	cout << "z+1 points to (why does it look random?)" << *(z+1) << endl;

	char* A = "012345";
	char *B = A;
	cout << "B" << B << endl;
	cout << "(B + 2)[1]" << (B + 2)[1] << endl;
	B +=1;
	cout << "(B + 1)" << *B << endl;
	B -=1;
	cout << "*(B -1)" << *B << endl;

}

void pointers_new() {

	//uninitialized
	int *myint = new int;

	//initialized
	int *myint1 = new int(10);

	//uninitialized
	int *myint2 = new int[20];

	//set it to zero
	memset(myint2, 0, 20 *sizeof(int));

	for (int i = 0; i < 20; i++)
		*(myint2 + i) = i;

	//clean up
	delete myint;
	delete myint1;
	delete []myint2;
}

void pointers_new_objects() {
	Flower* newFlower;
	newFlower = new Flower;

	(*newFlower).grow();	//equivs
	newFlower->grow();

	delete newFlower;

	//what about when you add pointers to a vector
	std::vector<Flower*> mv;

	//add 10 pointers to the vector
	for (int i = 0; i < 10; i++) {
		newFlower = new Flower;
		mv.push_back(newFlower);
	}

	//clean up the memory stored in vector
	for (std::vector<Flower*>::iterator myIter = mv.begin(); myIter < mv.end(); myIter++)
		delete (*myIter);
}


int main()
{
	Flower newFlower;
	newFlower.grow();
	newFlower.bloom(YELLOW);

	std::vector<Flower> mv;
	mv.push_back(newFlower);

	pointers_warmup();
	pointers_new();
	pointers_new_objects();
}




