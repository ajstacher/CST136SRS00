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
	double probability = 0;
	//1 for win 0 for loose

public:

	//default constructor
	Lmad();

	//constructor
	Lmad(int d, int disc, bool strat) {

		numOfDoors = d;
		disclosed = disc; 
		strategy = strat;

	}

	

	bool simulate(){
		//Doors numbers: 0 for goat, 1 for car, for disclosed goat door

		//1 for win 0 for loose
		bool outcome = 0;

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

		//****DEBUG OUTPUT******
		cout << "Current placement of car: \n";
		for (vector<int>::iterator i = doors.begin(); i != doors.end(); ++i) {
			cout << *i;
			cout << "\n" << endl;
		}


		//randomly pick door as contestant
		auto randomPickDoor = distribution(generator);
		//****DEBUG OUTPUT******
		cout << "The door picked by contestant is: ";
		cout << (randomPickDoor + 1);

		//If strategy is switch
		if(strategy == 0) {
			//for each door
			for (vector<int>::iterator i = doors.begin(); i != doors.end(); ++i) {
				//if door is a goat and door is not the picked door
				if ((*i == 0) && (i != doors.begin() + randomPickDoor) ) {
					//disclose dooor by removing it from vector
					*i = 2;
				}
			}
			//****DEBUG OUTPUT******
			cout << "\nThis is doors after removal: \n";
			for (vector<int>::iterator i = doors.begin(); i != doors.end(); ++i) {
				cout << *i;
				cout << "\n" << endl;
			}

		}
		else if(strategy = 1){
			//if strategy is stay



		}
		

		//if car is behind picked door and strategy is stay set outcome to 1

		//if not and strategy is stay set outcome to 0 for lose

		//if car is behind door and strategy is change set outcome to 0 for lose

		//if not and strategy is change randomly pick another door and check if car is behind it

		return outcome;
	}

};


int main(int argc, char *argv[])
{
	int numOfDoors, numOfDisc, instances = 0;
	bool strategy = 0;

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
	
	
	Lmad game(5, 3, 0); //passed in num of doors, num of disclosed, strategy
	game.simulate();

	int temp = 0;
	cin >> temp;


	/*/DEBUGGING*****************************************************************

	numOfDoors = 10;
	//create a vector of doors
	vector <int> doors(numOfDoors, 0);


	//rand generator
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distribution(0, numOfDoors - 1);
	//var for random number
	auto randomNumber = distribution(generator);
	//cout for varification
	cout << randomNumber;
	cout << "\n" << "\n";
	//pick a random door
	//put car behind it
	doors.at(randomNumber) = 1;
	

	for (vector<int>::iterator i = doors.begin(); i != doors.end(); ++i) {
		cout << *i;
		cout << "\n";
	}



	int temp = 0;
	cin >> temp;

	/*numOfDoors = atoi(argv[1]);

	cout << numOfDoors;*/
	//DEBUGGING******************************************************************/
	


    return 0;
}


