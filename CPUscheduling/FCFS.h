#pragma once
#include "Process.h"
#include <string>
#include <iostream>

using namespace std;



class FCFS {
public:
	void firstComeFirstServe(Process *arr, int size) {
		int *wait = new int[size];
		int *completion = new int[size];
		int completionTime = 0;
		int *turnAround = new int[size];
		int avgWait = 0;
		int avgTurnaround = 0;
		int avgResponse = 0;
		Process *temp = new Process[size];
		int cpuIsBusy = 0;
		int count = 0;

		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
			cpuIsBusy = cpuIsBusy + temp[i].getBurstTime();
		}
		//Bubble sort
		for (int i = 0; i < size - 1; i++) {
			bool flag = false;
			for (int j = 0; j < size - 1; j++) {
				if (temp[j].getArrival() > temp[j + 1].getArrival()) {
					Process swap = temp[j];
					temp[j] = temp[j + 1];
					temp[j + 1] = swap;
					flag = true;
				}
			}
			if (flag == false) {
				break;
			}
		}
		cout << "Gantt Chart:" << endl;
		int pid = temp[0].getProcessID();
		int cpuIdle = temp[0].getArrival();
		if (cpuIdle != 0) {
			cout << "0-cpu idle till-" << cpuIdle << " ";
		}
		for (int i = 0; i < size; i++) {
			int cpuBurst = temp[i].getBurstTime();
			completion[i] = 0;
			while (cpuBurst != 0) {
				if (cpuBurst == temp[i].getBurstTime()) {
					temp[i].setResponse(count + cpuIdle);
				}
				cout << "P" << temp[i].getProcessID() << " ";
				completionTime = completionTime + 1;
				cpuBurst--;
				count++;
			}
			if (temp[i].getProcessID() != pid) {
				completion[i] = completionTime + cpuIdle;
			}
			else {
				completion[i] = completionTime;
			}
			turnAround[i] = completion[i] - temp[i].getArrival();

			avgTurnaround = avgTurnaround + turnAround[i];

			wait[i] = turnAround[i] - temp[i].getBurstTime();
			avgWait = avgWait + wait[i];
		}
		cout << endl;
		if (cpuIdle != 0) {
			cout << "                 ";
		}
		for (int i = cpuIdle; i <= cpuIsBusy + cpuIdle; i++) {
			if (i < 10) {
				cout << i << " |";
			}
			else
				cout << i << "|";
		}
		cout << endl;
		cout << "Process     Arrival Time     Burst Time     Waiting time     completion time     Turn around time     Response time" << endl;
		for (int i = 0; i < size; i++) {
			cout << temp[i].getProcessID() << "                 " << temp[i].getArrival() << "                 " << temp[i].getBurstTime() << "                 " << wait[i] << "                 " << completion[i] << "                 " << turnAround[i] << "                 " << temp[i].getResponse() << endl;
			avgResponse = avgResponse + temp[i].getResponse();
		}
		cout << endl;
		cout << "average waiting time= " << float(avgWait) / float(size) << endl;
		cout << "average turn around time= " << float(avgTurnaround) / float(size) << endl;
		cout << "average response time= " << float(avgResponse) / float(size) << endl;
	}
};
