// MontyHall.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

class Lmad {
	//This class creates an instance of a lets make a deal type game

	//vars
	int numOfDoors = 3;
	int disclosed = 1;
	bool strategy = 0; //0 for switch 1 for stay

public:

	//constructor
	Lmad(int d, int disc, bool strat) {

		numOfDoors = d;
		disclosed = disc;
		strategy = strat;

	}

	bool simulate() {
		//This function simulates a game based on strategy passed in
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
	//vars
	int numOfDoors, numOfDisc, instances = 0;
	bool strategy = 0;
	auto wins = 0.0;
	auto losses = 0.0;
	auto probability = 0.0;
	auto temp = 0;

	//first make sure we have any args 
	if (argc < 2) {
	
		cout << "This program requires at least 2 arguments (strategy and umber of instances)\n";
		cout << "arg1 = Strategy -> 0 for Switch or 1 for Stay\n";
		cout << "arg2 = Number of game instances\n";
		cout << "arg3 = Number of doors (default == 3)\n";
		cout << "arg4 = Number of doors to disclose (default == 1)\n";
		cout << "Press any key then Enter to exit and retry\n";
		cin >> temp;
		exit(0);
	
	}
	
	//check input
	for (int i = 1; i < argc; i++) {
		
		//check if arg is negative
		if (atoi(argv[i]) < 0) {

			cout << "args must integers greater than zero!\n";
			cout << "Press any key then Enter to exit and retry\n";
			cin >> temp;
			exit(0);
		}
	
	}

	//number of args switch
	switch (argc) {
		case 1 : //redundant
		case 2 :
			cout << "This program requires at least 2 arguments (strategy and umber of instances)\n";
			cout << "arg1 = Strategy -> 0 for Switch or 1 for Stay\n";
			cout << "arg2 = Number of game instances\n";
			cout << "arg3 = Number of doors (default == 3)\n";
			cout << "arg4 = Number of doors to disclose (default == 1)\n";
			cout << "Press any key then Enter to exit and retry\n";
			cin >> temp;
			exit(0);
		case 3 :
			strategy = atoi(argv[1]);
			instances = atoi(argv[2]);
			numOfDoors = 3;
			numOfDisc = 1;
			break;
		case 4 :
			strategy = atoi(argv[1]);
			instances = atoi(argv[2]);
			numOfDoors = atoi(argv[3]);
			numOfDisc = 1;
			break;
		case 5 :
			strategy = atoi(argv[1]);
			instances = atoi(argv[2]);
			numOfDoors = atoi(argv[3]);
			numOfDisc = atoi(argv[4]);
			break;
		default :
			cout << "You really screwed up :( but I still love you, see you at Thanksgiving.\n";
			cout << "Press any key then Enter to exit and retry\n";
			cin >> temp;
			exit(0);
	}

	//create a vector of Lmad games
	vector <Lmad> games;

	//iterate through vector
	for (int i = 0; i < instances; i++) {

		//create game and push it to vector
		Lmad game(numOfDoors, numOfDisc, strategy);
		games.push_back(game);

	}

	//iterate through games in vector
	for (auto & game : games) {

		//if simulate returns a win
		if (game.simulate()) {

			//add a win
			wins++;

		}
		else {

			//if returns a loss
			losses++;
		}
	}

	//probability
	probability = wins / instances;
	assert(instances == wins + losses);
	cout << fixed << setprecision(2) << probability;
	cin >> temp;

	return 0;		
}
		

	

	

	

