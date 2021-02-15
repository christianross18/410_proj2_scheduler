/*
 * Dispatcher.h
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 *
 *      moves processes on and off the CPU
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_
#include "constants.h"
#include "CPU.h"

class Dispatcher {
public:
	Dispatcher(CPU &cpu):cpu(&cpu),is_valid_job_on_cpu(false){}
	virtual ~Dispatcher(){};

	//pull current process (if any) off CPU and return it
	//if nothing on CPU returns an uninitialized PCB
	PCB get_from_CPU();

	//place the current process on the CPU for execution
	void put_on_CPU(PCB  &process);

	//is CPU idle or working
	bool isValidJobOnCPU();
private:
	CPU *cpu; 	//this is initialized from a reference, it cannot be null
	bool is_valid_job_on_cpu;		//set or reset according to whether  there is a job on the CPU
};

#endif /* DISPATCHER_H_ */
