#pragma once
#include "Process.h"
#include <string>
#include <iostream>


using namespace std;



class RoundRobin {
public:
	void quantumScheduling(Process *arr, int size, int quantum) {
		int *turnaround = new int[size];
		int count = 0;
		int index = 0;
		int end = 0;
		int avgWait = 0;
		int avgTurn = 0;
		int avgResponse = 0;
		int *burst = new int[size];
		Process *ready = new Process[size];
		int queueCounter = 0;
		int *wait = new int[size];
		Process *temp = new Process[size];
		int i = 0; //int burst = 0;
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
			burst[i] = temp[i].getBurstTime();
			end += temp[i].getBurstTime();
		}
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
		int top = 1;
		ready[0] = temp[0];
		while (end != 0) {

			if (ready[index].getBurstTime() == 0) {
				index++;
			}
			else {
				int timeslice = 0;
				while (ready[index].getBurstTime() != 0 && timeslice <= quantum - 1) {
					if (ready[i].getBurstTime() == ready[i].getCpuBurst()) {
						ready[i].setResponse(count + cpuIdle);
					}
					cout << "P" << ready[index].getProcessID() << " ";
					ready[index].setBurstTime(ready[index].getBurstTime() - 1);
					count++;
					for (int j = 1; j < size; j++) {
						if (count == temp[j].getArrival()) {
							ready[top++] = temp[j];
						}
					}
					timeslice++;
					end--;
					ready[index].setCompletion(count);
				}
				Process swap = ready[index];

				for (int i = 0; i < top - 1; i++) {
					ready[i] = ready[i + 1];
				}
				ready[top - 1] = swap;
			}
		}
		for (int i = 0; i < size; i++) {
			if (ready[i].getProcessID() != pid) {
				ready[i].setCompletion(ready[i].getCompletion() + cpuIdle);
			}
			else {
				ready[i].setCompletion(ready[i].getCompletion());
			}
			ready[i].setTurnaroundTime(ready[i].getCompletion() - ready[i].getArrival());
			int waitTime = ready[i].getTurnaroundTime() - ready[i].getCpuBurst();
			ready[i].setWait(waitTime);
			avgWait += ready[i].getWait();
			avgTurn += ready[i].getTurnaroundTime();
		}
		cout << endl;
		if (cpuIdle != 0) {
			cout << "                 ";
		}
		for (int i = cpuIdle; i <= count + cpuIdle; i++) {
			if (i < 10) {
				cout << i << " |";
			}
			else
				cout << i << "|";
		}
		cout << endl;
		cout << "Process     Arrival Time     Burst Time     Waiting time     completion time     Turn around time     Response time" << endl;
		for (int i = 0; i < size; i++) {
			cout << ready[i].getProcessID() << "                 " << ready[i].getArrival() << "                 " << ready[i].getCpuBurst() << "                 " << ready[i].getWait() << "                 " << ready[i].getCompletion() << "                 " << ready[i].getTurnaroundTime() << "                 " << ready[i].getResponse() << endl;
			avgResponse = avgResponse + ready[i].getResponse();
		}
		cout << endl;
		cout << "average waiting time= " << float(avgWait) / float(size) << endl;
		cout << "average turn around time= " << float(avgTurn) / float(size) << endl;
		cout << "average response time= " << float(avgResponse) / float(size) << endl;
	}


};