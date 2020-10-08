#pragma once
#include<queue>
#include<iostream>

using namespace std;

queue<int>* const myqueue = new queue<int>[5];

/** --------------------------------------------------------
* @file    Queue.h
* @author  Noah Funderburgh
* @version 1.0
* @date 2/19/19
*
* CS162-01 - Assignment 4
	* Generates a priority queue
*
* ------------------------------------------------------------ */


class priorityQueue {
public:

	/**
*
*
*   @param letter - the character to be checked
*   @return true if letter is a vowel (a,e,i,o,u),
*		 false otherwise
*/
	priorityQueue();
	/**
*	To insert into priority queue, if you can't insert
	a priorty will says its invalid.
*
*	@param time - amount of time given to the object
*	@param priority - the importance of a given program or object
	0(highest) - 4(lowest)
*/
	void enqueue(int time, int priority);
	/**
*	To Remove items out of the priority queue
*
*   @param data - the data specitfyed to be removed
*
*/
	void dequeue(int& data);
	/**
*	To output the given info,
*			Intial		 Time	 Time	 Time		Final
*	PID		Priority   Needed  Started    Ended      Priority
*/
	void outputInfo();
	/**
*	calculates time in the queue by poping it off the queue adding timeNeeded to the clock.
*	The Max amount of time added is 20ms. When items get pushed back onto the queue their priority get lower
*	by one. The lowest priority possible is 4.
*/
	void calculateTimeInQueue();

	void orgizeData();

	void LoopDataIntoEnqueue();
	void copyTimeArray();


	
	int timeStarted = 0;
	int clock = 0;
	int time = 0;
	int storedData[4][20];
	int priority[6];
	int timeNeeded[6];
	int timeLeft[6];
	int Id[6];
	int amountInList = 0;

private:


};

priorityQueue::priorityQueue() {

}

void priorityQueue::enqueue(int Id, int priority) {

	if (priority > 4 || priority < 0) {
		priority = 4;
		cout << "Invalid priority, priority has been set to 4";
	}

	myqueue[priority].push(Id);
}

void priorityQueue::dequeue(int& data) {
	for (int pri = 4; pri >= 0; pri--) {
		if (myqueue[pri].empty()) {
			myqueue[pri].front();
			return;
		}
		return;
	}
}

void priorityQueue::outputInfo() {
	cout << "Author: Noah Funderburgh" << endl;
	cout << "	Initial     Time    Time       Time        Final" << endl;
	cout << "PID	Priority   Needed  Started    Ended      Priority" << endl;
}

void priorityQueue::calculateTimeInQueue() {
	int sizeOfQueue = 0;
	int i = 0;
	int PoppedOff = 0;
	int currentPriority = 0;
	int maxPriority = 4;
	while (currentPriority <= 4) {
		sizeOfQueue = myqueue[currentPriority].size();
		while (sizeOfQueue != 0) {

			sizeOfQueue = myqueue[currentPriority].size();
			if (sizeOfQueue != 0) {
				time = timeLeft[i];
				if (time > 20) {
					clock = clock + 20;
					timeLeft[i] = time - 20;
				}
				else
				{
					clock = clock + time;
					timeLeft[i] = time - time;
				}

				if (timeLeft[i] <= 0) {
					myqueue[currentPriority].pop();
					cout << Id[i] << "          " << priority[i] << "          " << timeNeeded[i] << "      " << timeStarted << "        " << clock << "          " << currentPriority << endl;
					i++;
				}
				else
				{
					myqueue[currentPriority].pop();
					if (currentPriority + 1 <= maxPriority)
						myqueue[currentPriority + 1].push(Id[i]);
					else
						myqueue[currentPriority].push(Id[i]);
				}
			}
		}
		currentPriority++;
	}
}


void priorityQueue::orgizeData() {
	int loopingThroughArray2 = amountInList - 2;
	int loopingThroughArray1 = amountInList - 2;
	for (int i = 0; i < loopingThroughArray2; i++) {
		for (int x = 0; x <= loopingThroughArray1; ++x) {
			
			if (priority[x] == priority[x + 1]) {
				if (timeNeeded[x] > timeNeeded[x + 1]) {
					int temp3 = NULL;
					int temp4 = NULL;
					temp3 = timeNeeded[x];
					temp4 = timeNeeded[x + 1];
					timeNeeded[x] = temp4;
					timeNeeded[x + 1] = temp3;
				}
			}
			if (priority[x] > priority[x + 1]) {

				int temp3 = NULL;
				int temp4 = NULL;
				
				temp3 = timeNeeded[x];
				temp4 = timeNeeded[x + 1];
				timeNeeded[x] = temp4;
				timeNeeded[x + 1] = temp3;
				
				
				int temp1 = NULL;
				int temp2 = NULL;
				
				temp1 = priority[x];
				temp2 = priority[x + 1];
				priority[x] = temp2;
				priority[x + 1] = temp1;
			}
		}
	}
}

void priorityQueue::LoopDataIntoEnqueue() {
	int something = amountInList - 1;
	for (int i = 0; i <= something; i++) {
		enqueue(Id[i], priority[i]);
	}

}

void priorityQueue::copyTimeArray() {
	int loopValue = amountInList - 1;
	for (int i = 0; i <= loopValue;i++) {
		timeLeft[i] = timeNeeded[i];
	}
}