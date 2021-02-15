/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/dispatcher.h"

Dispatcher( CPU  &cpu):cpu(&cpu),is_valid_job_on_cpu(false){}
PCB Dispatcher::get_from_CPU(){
	return (cpu->get_COPY_of_Current_Process());
}

void Dispatcher::put_on_CPU(PCB &process){
	cpu->put_process_on_core(process);
}

bool Dispatcher::isValidJobOnCPU(){
	return is_valid_job_on_cpu;
}
