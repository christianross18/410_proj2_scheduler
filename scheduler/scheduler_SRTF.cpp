/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"
#include "../includes/file_io.h"
#include <numeric>
#include <math.h>
#include <algorithm>
#include <vector>

// calls parent
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	return Scheduler::time_to_switch_processes(tick_count, p);
}
//sorts by remaining cpu time, used functionality in file_io.cpp
void Scheduler_SRTF::sort(){
	std::vector<PCB> temp;
	while(!ready_q->empty()){
		temp.push_back(ready_q->front());
		ready_q->pop();
	}
	SORT_ORDER a= CPU_TIME;
	sortData(a);
	for(PCB i:temp){
		ready_q->push(i);
	}
}
