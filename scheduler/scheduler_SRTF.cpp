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
	sort();
	if(ready_q->front().remaining_cpu_time<p.remaining_cpu_time){
		return true;
	}
	return Scheduler::time_to_switch_processes(tick_count, p);
}
//sorts by remaining cpu time, used functionality in file_io.cpp
void Scheduler_SRTF::sort(){
	std::vector<PCB> temp;
	while(!ready_q->empty()){
		temp.push_back(ready_q->front());
		ready_q->pop();
	}
	for(int i=temp.size()-1;i>=0;i--){
		int max=temp[0].remaining_cpu_time;
		int index=0;
		for(int j=0;j<=i;j++){
			if(temp[j].remaining_cpu_time>max){
				max=temp[j].remaining_cpu_time;
				index=j;
			}
		}
		PCB t = temp[i];
		temp[i]=temp[index];
		temp[index]=t;
	}
	for(PCB i:temp){
		ready_q->push(i);
	}
}
