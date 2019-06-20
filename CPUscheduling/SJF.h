#pragma once
#include "Process.h"
#include <string>
#include <iostream>


using namespace std;



class SJF {
public:
	void shortestJobFirst(Process *arr, int size) {
		cout << "Shortest Job First(Non-preemptive)" << endl;

		int completionTime = 0;
		int avgWait = 0;
		int avgTurnaround = 0;
		int avgResponse = 0;
		Process *temp = new Process[size];
		int end = 0;

		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
			end = end + temp[i].getBurstTime();
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
		}int count = 0;
		cout << "Gantt Chart:" << endl;
		int pid = temp[0].getProcessID();
		int cpuIdle = temp[0].getArrival();
		if (cpuIdle != 0) {
			cout << "0-cpu idle till-" << cpuIdle << " ";
		}
		Process *ready = new Process[size];
		ready[0] = temp[0];
		int top = 1;
		count = count + ready[0].getArrival();
		for (int i = 0; i < size; i++) {
			int burst = ready[i].getBurstTime();
			while (burst != 0) {
				if (burst == ready[i].getBurstTime()) {
					ready[i].setResponse(count);
				}
				cout << "P" << ready[i].getProcessID() << " ";
				completionTime = completionTime + 1;
				burst--;
				count++;
				for (int j = 1; j < size; j++) {
					if (count == temp[j].getArrival()) {
						ready[top++] = temp[j];
					}
				}
			}
			if (ready[i].getProcessID() != pid) {
				ready[i].setCompletion(completionTime + cpuIdle);
			}
			else {
				ready[i].setCompletion(completionTime);
			}

			ready[i].setTurnaroundTime(ready[i].getCompletion() - ready[i].getArrival());
			avgTurnaround = avgTurnaround + ready[i].getTurnaroundTime();
			ready[i].setWait(ready[i].getTurnaroundTime() - ready[i].getBurstTime());
			avgWait = avgWait + ready[i].getWait();
			if (i != size - 1) {
				processSort(i + 1, ready, top);
			}
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
			cout << ready[i].getProcessID() << "                 " << ready[i].getArrival() << "                 " << ready[i].getBurstTime() << "                 " << ready[i].getWait() << "                 " << ready[i].getCompletion() << "                 " << ready[i].getTurnaroundTime() << "                 " << ready[i].getResponse() << endl;
			avgResponse = avgResponse + ready[i].getResponse();
		}
		cout << endl;
		cout << "average waiting time= " << float(avgWait) / float(size) << endl;
		cout << "average turn around time= " << float(avgTurnaround) / float(size) << endl;
		cout << "average response time= " << float(avgResponse) / float(size) << endl;
	}

	void processSort(int start, Process* temp, int size) {
		for (int i = start; i < size - 1; i++) {
			bool flag = false;
			for (int j = start; j < size - 1; j++) {
				if (temp[j].getBurstTime() > temp[j + 1].getBurstTime()) {
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
	}
};
