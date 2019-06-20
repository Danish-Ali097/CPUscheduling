#pragma once
#include"Process.h"
#include<iostream>
#include<string>

using namespace std;

class SJFpre
{
public:
	void shortestJobFirst(Process *arr, int size)
	{
		cout << "Shortest Job First(Preemptive)" << endl;
		int *wait = new int[size];
		int *completion = new int[size];
		int *turnAround = new int[size];
		int completionTime = 0;
		int avgWait = 0;
		int avgTurnaround = 0;
		int avgResponce = 0;
		Process *temp = new Process[size];
		for (int i = 0; i < 5; i++)
		{
			temp[i] = arr[i];
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
				if (temp[j].getArrival() == temp[j + 1].getArrival()) {
					if (temp[j].getBurstTime() > temp[j + 1].getBurstTime()) {
						Process swap = temp[j];
						temp[j] = temp[j + 1];
						temp[j + 1] = swap;
						flag = true;
					}
				}
			}
			if (flag == false) {
				break;
			}
		} 
		//values after swap
		/*cout << "values and processes before Gantt chart\n";
		for (int k = 0; k < size; k++)
		{
		cout << "\nP" << temp[k].getProcessID() << "\t arrival " << temp[k].getArrival() << "\t brust " << temp[k].getBurstTime() << endl;
		}*/
		cout << "Gantt Chart:" << endl;
		int cpuBurst = 0;
		int count = 0;
		int totalBurst = 0;
		int procburst[5] = { 0 };

		for (int i = 0; i < size; i++)
		{
			completion[i] = 0;
			procburst[i] = temp[i].getBurstTime();
			totalBurst = totalBurst + temp[i].getBurstTime();
		}
		//cout << "Total burst time : " << totalBurst << endl;
		int i = 0;
		int cpuIdle = temp[i].getArrival();
		if (cpuIdle != 0)
		{
			cout << "0-cpu idle till-" << cpuIdle << " ";
		}
		while (cpuBurst != totalBurst) {

			completionTime++;


			cout << "P" << temp[i].getProcessID() << " ";
			cpuBurst++;
			temp[i].setBurstTime((temp[i].getBurstTime() - 1));
			for(int j=0;j<size;j++)
			{
				if (temp[i].getProcessID() == arr[j].getProcessID())
				{
					int sub = arr[j].getBurstTime() - temp[i].getBurstTime();
					if (sub == 1)
					{
						temp[i].setResponse(cpuBurst-1);
					}
				}
			}

			for (int j = 0; j < size; j++)
			{
				if (temp[j].getBurstTime() <= 0)
				{
					if (temp[i].getBurstTime() == 0)
					{
						completion[i] = completionTime;
					}
					continue;
				}
				//cout << "brust time of current process P"<< temp[i].getProcessID() <<" is : "<< temp[i].getBurstTime() <<"\t burst time of process P"<<temp[j].getProcessID() <<" is : "<< temp[j].getBurstTime()<<endl;
				if ((temp[i].getArrival() <= temp[j].getArrival()) && (temp[j].getBurstTime() < temp[i].getBurstTime()))
				{
					i = j;
				}
				if (temp[i].getBurstTime() == 0)
				{
					completion[i] = completionTime;
					i = j;
				}
			}


		}
		for (int i = 0; i<size; i++)
		{
			turnAround[i] = completion[i] - temp[i].getArrival();
			avgTurnaround = avgTurnaround + turnAround[i];
			wait[i] = turnAround[i] - procburst[i];
			avgWait = avgWait + wait[i];
			avgResponce = avgResponce + temp[i].getResponse();
		}
		cout << endl;
		if(cpuIdle!=0)
		{
			cout << "                 ";
		}else
		{
			for (int i = cpuIdle; i <= cpuBurst + cpuIdle; i++) {
				if (i < 10) {
					cout << i << " |";
				}
				else
					cout << i << "|";
			}
		}
		cout << endl;
		cout << "Process      Arrival Time      Burst Time      Waiting time      completion time      Turn around time     Response time" << endl;
		for (int i = 0; i < size; i++) {
			cout << temp[i].getProcessID() << "                   " << temp[i].getArrival() << "                   " << procburst[i] << "                   " << wait[i] << "                  " << completion[i] << "                  " << turnAround[i] << "               " << temp[i].getResponse() << endl;
		}
		cout << endl;
		cout << "average waiting time= " << float(avgWait) / float(size) << endl;
		cout << "average turn around time= " << float(avgTurnaround) / float(size) << endl;
		cout << "average response time= " << float(avgResponce) / float(size) << endl;
		//delete[] temp;
		//delete[] wait;
		//delete[] turnAround;
	}
};