/*
FCFS - This scheduling is nonpreemeptive. The process that requests the CPU first is allocated the CPU first.
		Processes are put into a queue for usage of the CPU. This scheduling algorithm often has a long average waiting time.

SJF (Preemptive) - This version of shortest job first is preemptive meaning that it will kick processes out of the CPU before they have a chance to finish.
				It is also called shortest-remaining-time-first scheduling.
				This scheduling algorithm takes into account the time of the processes' next CPU burst. 
				The process with the shortest next CPU burst will be able to use the CPU. If a process with a shorter burst time is available,
				the process that is currently using the CPU will be kicked out and the new process will acquire the CPU. 
				Although this algorithm can optimize CPU usage, there is a difficulty in knowing the length of the next CPU request. It can only be estimated.

SJF (Nonpreemptive) - This works the same way that the SJF above does except that it is nonpreemptive. 
				If a process has control of the CPU and a new process with a shorter burst time arrives, 
				the process currently in control of the CPU will get to finish before getting kicked out.

Priority - This scheduling algorithm allocates the CPU to the process with the highest priority. Processes with equal priority are scheduled in FCFS.
			This algorithm can be preemptive or nonpreemptive. The problem with this type of scheduling is that low priority process may never get to acquire
			the CPU. This is called starvation. The solution to this is by raising the priority of older processes. This is called aging.

Round Robin - This algorithm is naturally preemptive and designed for time-sharing systems. There is a time limit called quantum time which dictates
			how long a process gets to run in the CPU. After the time is up, the process is kicked out and the new process gets to use the CPU until its time is up.
			This process repeats until there are no more process left to use the CPU. If a process' time left is less than the quantum time, it will just use the time
			it takes to finish and move on to the next process. If there is only one process left in the round robin, it will be allocated and deallocated accordingly
			until it finishes. No process will ever get to completely hold on to the CPU.
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Process
{
	int id;
	int burstTime;
	int arrivalTime;
};

void swap(Process *xp, Process *yp)
{
	Process temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(Process arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].arrivalTime > arr[j + 1].arrivalTime)
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

int main()
{
	Process  prequeue[5];
	prequeue[0].arrivalTime = 0;
	prequeue[0].burstTime = 8;
	prequeue[0].id = 1;
	prequeue[1].arrivalTime = 2;
	prequeue[1].burstTime = 6;
	prequeue[1].id = 2;
	prequeue[2].arrivalTime = 2;
	prequeue[2].burstTime = 1;
	prequeue[2].id = 3;
	prequeue[3].arrivalTime = 1;
	prequeue[3].burstTime = 9;
	prequeue[3].id = 4;
	prequeue[4].arrivalTime = 3;
	prequeue[4].burstTime = 3;
	prequeue[4].id = 5;

	/*for (int index = 0; index < 5; index++)
	{
		int arrival;
		int burst;
		prequeue[index].id = index + 1;
		cout << "What is p[" << index + 1 << "]'s arrival time? ";
		cin >> arrival;
		cout << "What is p[" << index + 1 << "]'s burst time? ";
		cin >> burst;
		prequeue[index].arrivalTime = arrival;
		prequeue[index].burstTime = burst;
	}*/

	bubbleSort(prequeue, 5);
	int quantumTime;
	cout << "What is the quantum time? ";
	cin >> quantumTime;

	vector<Process> roundRobin;
	for (int index = 0; index < 5; index++)
	{
		roundRobin.push_back(prequeue[index]);
	}

	int counter = 0;
	while (!roundRobin.empty())
	{
		roundRobin[counter % roundRobin.size()].burstTime = roundRobin[counter % roundRobin.size()].burstTime - quantumTime;
		cout << roundRobin[counter % roundRobin.size()].id << "\t";

		if (roundRobin[counter % roundRobin.size()].burstTime <= 0)
		{
			roundRobin.erase(roundRobin.begin() + (counter % roundRobin.size()));
			if (roundRobin.size() % 2 == 0)
			{
				counter--;
			}
		}
		if (roundRobin.empty())
		{
			break;
		}
		
		counter++;
		if ((counter + 1) > roundRobin.size())
		{
			counter = 0;
		}
	}
	cout << endl;

	system("pause");
	return 0;
}