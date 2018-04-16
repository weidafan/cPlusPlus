#include <string>
#include "stdlib.h"
#include "../includes/externs.h"
#include "../includes/waiter.h"

using namespace std;

Waiter::Waiter(int id, std::string filename) :
		id(id), myIO(filename) {
}

Waiter::~Waiter() {
}
//gets next Order from file_IO
//if return == SUCCESS then anOrder
//contains new order
//otherwise return contains error
int Waiter::getNext(ORDER &anOrder) {
	return myIO.getNext(anOrder);
}
//contains a loop that will get orders from filename one at a time
//then puts them in order_in_Q then signals baker(s) using cv_order_inQ
//so they can be consumed by baker(s)
//when finished exits loop and signals baker(s) using cv_order_inQ that
//it is done using b_WaiterIsFinished
void Waiter::beWaiter() {
	ORDER anOrder = { };
	while (Waiter::getNext(anOrder) == SUCCESS) {
		{
			std::unique_lock<mutex> lk(mutex_order_inQ);
			cout<< "waiter made order: "<< anOrder.order_number<<" #donuts: "<<anOrder.number_donuts<< endl;
			order_in_Q.push(anOrder);
		}
			cv_order_inQ.notify_all();
	}

	{
		std::unique_lock<mutex> lk(mutex_order_inQ);
		b_WaiterIsFinished = true;
		cout << "Waiter has no more order!! waiter exiting!" << endl;
	}
	cv_order_inQ.notify_all();
}

