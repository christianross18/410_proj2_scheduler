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
	float total_strt =0, total_arvl =0, total_fin=0, total_cpu  = 0;
	float total_proc =0;
	for(PCB a : *vec){
		total_strt+= a.start_time;
		total_arvl+= a.arrival_time;
		total_fin+=a.finish_time;
		total_cpu+= a.required_cpu_time;
		total_proc++;
	}
	av_response_time=(total_strt-total_arvl)/total_proc;
	av_turnaround_time=(total_fin-total_arvl)/total_proc;
	av_wait_time=(total_fin-total_arvl-total_cpu)/total_proc;
}
