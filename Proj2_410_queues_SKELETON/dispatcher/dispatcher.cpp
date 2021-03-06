#include "../includes_usr/constants.h"
#include "../includes_usr/dispatcher.h"
#include "../includes_usr/file_io.h"
#include "../includes_usr/joblist.h"
#include "../includes_usr/logger_single_thread.h"
#include <queue>
std::queue<PCB> ready_Q;
std::queue<PCB> blocked_Q;
PCB runningPCB;
//clears ready_Q and blocked_Q these are queues of PCB structures,
//initializes runningPCB to default values in constants (see PCB structure)
void dispatcher::init() {
	while (!ready_Q.empty()) {
		ready_Q.pop();
	}
	while (!blocked_Q.empty()) {
		blocked_Q.pop();
	}
	runningPCB.process_number = UNINITIALIZED;
	runningPCB.start_time = UNINITIALIZED;
	runningPCB.cpu_time = UNINITIALIZED;
	runningPCB.io_time = UNINITIALIZED;

}
//used for testing, return a copy of runningPCB
PCB dispatcher::getCurrentJob() {
	return runningPCB;
}
//add a job to the ready queue
void dispatcher::addJob(PCB &myPCB) {
	ready_Q.push(myPCB);
}
//interrupt can be either;
//a switch process interrupt in which case the function performs the appropriate tasks and returns PCB_SWITCHED_PROCESSES
//or a io_complete interrupt in which case it pulls ALL processes off of the blockedQ and returns either PCB_MOVED_FROM_BLOCKED_TO_READY (if there were any)
//or PCB_BLOCKED_QUEUE_EMPTY if there were none.
int dispatcher::processInterrupt(int interrupt) {
	if (interrupt == SWITCH_PROCESS) {
		if (ready_Q.empty() && blocked_Q.empty()) {
			return NO_JOBS;
		} else if (ready_Q.empty() && !blocked_Q.empty()) {
			return BLOCKED_JOBS;
		} else {
			if (runningPCB.process_number != UNINITIALIZED) {
				ready_Q.push(runningPCB);
			}
			runningPCB = ready_Q.front();
			ready_Q.pop();
			return PCB_SWITCHED_PROCESSES;
		}
	}
	if (interrupt == IO_COMPLETE) {
		if (!blocked_Q.empty()) {
			while (!blocked_Q.empty()) {
				ready_Q.push(blocked_Q.front());
				blocked_Q.pop();
			}
			return PCB_MOVED_FROM_BLOCKED_TO_READY;
		} else {
			return PCB_BLOCKED_QUEUE_EMPTY;
		}
	}
	return PCB_UNIMPLEMENTED;
}
//see flowchart
int dispatcher::doTick() {
	//	std::cout << "cpu time" << runningPCB.cpu_time << std::endl;
	if (runningPCB.start_time != UNINITIALIZED) {
		if (runningPCB.cpu_time != 0) {
			runningPCB.cpu_time -= 1;
		}
		if (runningPCB.cpu_time == 0) {
			if (runningPCB.io_time == 0) {
				runningPCB.process_number = UNINITIALIZED;
				runningPCB.start_time = UNINITIALIZED;
				runningPCB.cpu_time = UNINITIALIZED;
				runningPCB.io_time = UNINITIALIZED;
				return PCB_FINISHED;
			} else {
				runningPCB.io_time = 0;
				blocked_Q.push(runningPCB);
				runningPCB.process_number = UNINITIALIZED;
				runningPCB.start_time = UNINITIALIZED;
				runningPCB.cpu_time = UNINITIALIZED;
				runningPCB.io_time = UNINITIALIZED;
				return PCB_ADDED_TO_BLOCKED_QUEUE;
			}
		} else {
			return PCB_CPUTIME_DECREMENTED;
		}
	} else {
		if (ready_Q.empty()) {
			if (blocked_Q.empty()) {
				return NO_JOBS;
			} else {
				return BLOCKED_JOBS;
			}
		} else {
			runningPCB = ready_Q.front();
			ready_Q.pop();
			return PCB_MOVED_FROM_READY_TO_RUNNING;
		}
	}
}
