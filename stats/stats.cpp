/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */
#include <vector>
#include <iostream>
#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;
	calcStats();
}

void Stats::showAllProcessInfo(){
	int i=1;
	for(PCB a : *vec){
		std::cout<<"Program "<< i << " Required CPU time:"<<a.required_cpu_time
				<<"  arrived:"<<a.arrival_time<<" started:"
				<<a.start_time<<" finished:"<<a.finish_time <<std::endl;
		i++;
	}
}
float Stats::get_av_response_time(){
	return av_response_time;
}
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}
float Stats::get_av_wait_time(){
	return av_wait_time;
}
void Stats::calcStats(){
	for(PCB a : *vec){
		av_response_time+= a.start_time-a.arrival_time;
		av_turnaround_time+=a.finish_time-a.arrival_time;
		av_wait_time+=a.finish_time-a.arrival_time-a.required_cpu_time;
	}
	av_response_time/=3;
	av_turnaround_time/=3;
	av_wait_time/=3;
}
