// MontyHall.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;


int main(int argc, char *argv[])
{
	int numOfDoors, numOfDisc, instances = 0;
	bool strategy = 0;

	//argument 0 is the is the path to the .exe

	//check for correct number of args
	if (argc != 4) {
		cout << "This program requires 4 arguments \n";    
		cout << "arg1 = Number of doors \n";
		cout << "arg2 = Number of doors to disclose \n";
		cout << "arg3 = Number of game instances \n";
		cout << "arg4 = Strategy -> 0 for Switch or 1 for Stay \n";
		cout << "Please exit and retry with the correct number of arguments!\n";
	}



	int temp = 0;
	cin >> temp;

	/*numOfDoors = atoi(argv[1]);

	cout << numOfDoors;*/

	


    return 0;
}

