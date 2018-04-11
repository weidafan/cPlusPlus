#include <mutex>
#include "../includes/externs.h"
#include "../includes/baker.h"
#include <math.h>
#include <mutex>
using namespace std;
mutex m;
Baker::Baker(int id) :
		id(id) {
}

Baker::~Baker() {
}
//bake, box and append to anOrder.boxes vector
//if order has 13 donuts there should be 2 boxes
//1 with 12 donuts, 1 with 1 donut
void Baker::bake_and_box(ORDER &anOrder) {
	anOrder = order_in_Q.front();
	order_in_Q.pop();
	int num_donut = anOrder.number_donuts;
	while (num_donut > 0) {
		Box box;
		DONUT aDonut;
		if (num_donut > 12) {
			while (box.addDonut(aDonut)) {
				num_donut--;
			}
		} else {
			while (num_donut-- > 0) {
				box.addDonut(aDonut);
			}
		}
		anOrder.boxes.push_back(box);
	}

}
//as long as there are orders in order_in_Q then
//for each order:
//	create box(es) filled with number of donuts in the order
//  then place finished order on order_outvector
//  if waiter is finished (b_WaiterIsFinished) then
//  finish up remaining orders in order_in_Q and exit
//
//You will use cv_order_inQ to be notified by waiter
//when either order_in_Q.size() > 0 or b_WaiterIsFinished == true
//hint: wait for something to be in order_in_Q or b_WaiterIsFinished == true
void Baker::beBaker() {
	{
		std::unique_lock<mutex> lk(mutex_order_inQ);
		while (order_in_Q.size() == 0) {
			cv_order_inQ.wait(lk);
		}
	}
	while (order_in_Q.size() != 0) {
		//		{
		//		std::lock_guard<mutex> lk(mutex_order_outQ);
		ORDER anOrder;
		bake_and_box(anOrder);
		order_out_Vector.push_back(anOrder);
		m.lock();
		cout << "baker " << id << " made order: id: " << anOrder.order_number
				<< " #box:" << anOrder.boxes.size() << " #donut: "
				<< anOrder.number_donuts << endl;
		m.unlock();
	}
	{
		std::unique_lock<mutex> lk(mutex_order_inQ);
		while (!b_WaiterIsFinished) {
			cv_order_inQ.wait(lk);
		}
	}
	m.lock();
	cout << "  Baker " << id << " exiting" << endl;
	m.unlock();
}
