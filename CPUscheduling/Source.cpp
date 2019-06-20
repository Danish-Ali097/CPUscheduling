#include "FCFS.h"
#include "Process.h"
#include "SJF.h"
#include "PriorityScheduling.h"
#include "RoundRobin.h"
#include "Priorietypremptive.h"
#include "SJFpremtive.h"


#include <string>
#include <iostream>
using namespace std;

void main() {
	int choice = 0;
	bool loop = true;
	Process *array = new Process[5];
	array[0].setProcessID(1);
	array[0].setBurstTime(8);
	array[0].setcpuBurst(8);
	array[0].setPriority(1);
	array[0].setArrival(0);

	array[1].setProcessID(2);
	array[1].setBurstTime(4);
	array[1].setcpuBurst(4);
	array[1].setPriority(5);
	array[1].setArrival(2);

	array[2].setProcessID(3);
	array[2].setBurstTime(6);
	array[2].setcpuBurst(6);
	array[2].setPriority(2);
	array[2].setArrival(6);

	array[3].setProcessID(4);
	array[3].setBurstTime(4);
	array[3].setcpuBurst(4);
	array[3].setPriority(10);
	array[3].setArrival(1);

	array[4].setProcessID(5);
	array[4].setBurstTime(8);
	array[4].setcpuBurst(8);
	array[4].setPriority(9);
	array[4].setArrival(2);
	cout << "CPU Schedulers" << endl;
	do {
		system("color 0a");
		//menu
		cout << "\nEnter 1 for First Come First Serve." << endl;
		cout << "Enter 2 for Shortest Job First." << endl;
		cout << "Enter 3 for Shortest Remaining Job First." << endl;
		cout << "Enter 4 for Priority Scheduling." << endl;
		cout << "Enter 5 for Preemptive Priority Scheduling." << endl;
		cout << "Enter 6 for Round Robin." << endl;
		cout << "Enter 7 to exit." << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			//fcfs
			system("title First Come First Serve");
			//system("color 03");
			FCFS scheduler;
			scheduler.firstComeFirstServe(array, 5);
		}break;
		case 2: {
			//shortest job first
			system("title shortest job first");
			//system("color f0");
			SJF scheduler;
			scheduler.shortestJobFirst(array, 5);
		}break;
		case 3: {
			//shortest remaining job first
			system("title shortest remaining job first");
			//system("color 0a");
			SJFpre scheduler;
			scheduler.shortestJobFirst(array, 5);
		}break;
		case 4: {
			//priority
			system("title priority");
			//system("color 6f");
			PriorityScheduling ps;
			ps.priorityScheduling(array, 5);
		}break;
		case 5: {
			//preemptive priority
			system("title preemptive priority");
			//system("color f4");
			PrioritySchedulingPre ps;
			ps.priorityScheduling(array, 5);
		}break;
		case 6: {
			//round robin
			system("title round robin");
			//system("color 84");
			RoundRobin scheduler;
			scheduler.quantumScheduling(array, 5, 2);
		}break;
		case 7: {
			//exit
			loop = false;
			system("title Exit");
		}break;
		default: {
			system("title Invalid option");
			cout << "\aPlease enter a valid option.\n" << endl;
		}break;
		}
	} while (loop == true);

	//delete[] array;
	system("pause");
}