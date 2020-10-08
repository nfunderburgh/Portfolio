#pragma once

#include <fstream> //for file I/O  
#include"Queue.h"
#include <iostream> 
#include <string> 

using namespace std;

int main() {
	
	priorityQueue start;
	int sum(0.0), average, temp;
	

	ifstream myfile("sim.txt");

	if (!myfile.is_open())
	{
		cout << "Unable to open file";
		return 1;
	}

	while (myfile.good())	       // Good practice to check with good(), but
	{			       // if you KNOW it will only be 6 values, consider
		myfile >> start.priority[start.amountInList] >> start.timeNeeded[start.amountInList]; // a 1-to-6 for loop with if(myfile.good() inside
		start.Id[start.amountInList] = start.amountInList+1;
		start.amountInList++;
	}
	start.orgizeData();
	start.LoopDataIntoEnqueue();
	start.copyTimeArray();
	start.outputInfo();
	start.calculateTimeInQueue();

	
}

