// MontyHall.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <random>

using namespace std;

class Lmad {

	//vars
	int numOfDoors = 3;
	int disclosed = 1;
	bool strategy = 0; //0 for switch 1 for stay

public:

	//default constructor
	Lmad();

	//constructor
	Lmad(int d, int disc, bool strat) {

		numOfDoors = d;
		disclosed = disc;
		strategy = strat;

	}

	bool simulate() {
		//Doors numbers: 0 for goat, 1 for car, 2 for disclosed door

		//vars
		bool win = false; //1 for win 0 for loose
		bool simulationDone = false; //1 for win 0 for loose

		//rand generator
		std::random_device                  rand_dev;
		std::mt19937                        generator(rand_dev());
		std::uniform_int_distribution<int>  distribution(0, numOfDoors - 1);

		//create a vector of doors
		vector <int> doors(numOfDoors, 0);

		//pick a random door for car
		auto randomCarDoor = distribution(generator);

		//put car behind it
		doors.at(randomCarDoor) = 1;

		//randomly pick door as contestant
		auto randomPickDoor = distribution(generator);
		
		if (strategy == 0) { //Switch

			//set previous door
			auto previousDoorPick = randomPickDoor;

			//iterate through doors
			for (vector<int>::iterator i = doors.begin(); i != doors.end(); ++i) {

				//if door is a goat and door is not the picked door and there are still doors left to disclose
				if ((*i == 0) && (i != doors.begin() + randomPickDoor) && (disclosed > 0)) {

					//disclose dooor by changing val to 2
					*i = 2;
					disclosed--;

				}
			}

			while (!simulationDone) {

				//pick another door to switch to
				randomPickDoor = distribution(generator);

				//if next picked door is the car and isn't the previously picked door
				if (doors.at(randomPickDoor) == 1 && randomPickDoor != previousDoorPick) {

					//set as win
					win = true;
					simulationDone = true;


				} //if next picked door is a goat and not the previously picked door
				else if (doors.at(randomPickDoor) == 0 && randomPickDoor != previousDoorPick) {

					//set as lose
					win = false;
					simulationDone = true;

				}
				else {

					//set previous picked door
					previousDoorPick = randomPickDoor;

				}
			}
		}
		else if (strategy = 1) { //Stay
		
			//if door picked is a car set win
			if (doors.at(randomPickDoor) == 1) {

				win = true;

			}//if door picked is goat set lose
			else if (doors.at(randomPickDoor) != 1) {

				win = false;

			}
		}
		return win;
	}
};


int main(int argc, char *argv[])
{
	int numOfDoors, numOfDisc, instances = 0;
	bool strategy = 0;
	auto wins = 0;
	auto losses = 0;

	//argument 0 is the is the path to the .exe

	//check for correct number of args
	//+1 for path argument
	if (argc != 5) {
		cout << "This program requires 4 arguments \n";
		cout << "arg1 = Number of doors \n";
		cout << "arg2 = Number of doors to disclose \n";
		cout << "arg3 = Number of game instances \n";
		cout << "arg4 = Strategy -> 0 for Switch or 1 for Stay \n";
		cout << "Please exit and retry with the correct number of arguments!\n";
	} //do more input checking later
	//have to account fro default values in SRS


	Lmad game(5, 2, 1); //passed in num of doors, num of disclosed, strategy
	game.simulate();

	int temp = 0;
	cin >> temp;


	/*/DEBUGGING*****************************************************************

	//DEBUGGING******************************************************************/



	return 0;
}


