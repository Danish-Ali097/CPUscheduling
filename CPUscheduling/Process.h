#pragma once

class Process {
private:
	int processID;
	int burstTime;
	int priority;
	int arrival;
	int turnaround;
	int wait;
	int cpuBurst;
	int completion;
	int response;
public:

	void setProcessID(int id) {
		processID = id;
	}
	int getProcessID() {
		return processID;
	}
	void setResponse(int res) {
		response = res;
	}
	int getResponse() {
		return response;
	}
	void setCompletion(int cp) {
		completion = cp;
	}
	int getCompletion() {
		return completion;
	}
	void setTurnaroundTime(int tat) {
		turnaround = tat;
	}
	int getTurnaroundTime() {
		return turnaround;
	}
	void setWait(int wt) {
		wait = wt;
	}
	int getWait() {
		return wait;
	}
	void setBurstTime(int bt) {
		burstTime = bt;
	}
	void setcpuBurst(int bt) {
		cpuBurst = bt;
	}
	int getCpuBurst() {
		return cpuBurst;
	}
	int getBurstTime() {
		return burstTime;
	}
	void setPriority(int pr) {
		priority = pr;
	}
	int getPriority() {
		return priority;
	}
	void setArrival(int ar) {
		arrival = ar;
	}
	int getArrival() {
		return arrival;
	}
};