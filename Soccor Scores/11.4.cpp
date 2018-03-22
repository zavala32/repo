/*
 * Write a program that stores the following data about a soccer player in a structure:
 * Player’s NamePlayer’s Number
 * Points Scored by Player
 * The program should keep an array of 12 of these structures. 
 * Each element is for a different player on a team. When the program
 * runs it should ask the user to enter the data for each player.
 * It should then show a table that lists each player’s number, name,
 * and points scored. The program should also calculate and display the 
 * total points earned by the team. The number and name of the player 
 * who has earned the most points should also be displayed.
 */

/* 
 * File:   11.4.cpp
 * Author: Nicolas Zavala
 *
 * Created on March 22, 2018, 12:26 PM
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int SIZE = 50;
struct Player
  {
	char name[SIZE];        //Player's Name
	int playNum;            //Player's Number
	int Points;          //Point's Scored
};

const int NUM_PLAYERS = 3; //Number of Players
// Dynamically allocate the memory needed.
Player *players = new Player[NUM_PLAYERS];      //Array of structures
int total = 0;

void getPlayerInfo(Player &);
void showInfo(Player);
int  getTotalPoints(Player[], int);
void showHighest(Player[], int);

int main()
{
	getPlayerInfo(*players);
	getTotalPoints(players,total);
	showInfo(*players);

}

void getPlayerInfo(Player&)
{
	int index;
	

	// Get Player data.
	cout << "\nYou will need the following information.\n";
	cout << "Pertaining to your Soccer Players.\n";
	cout << "The Player's Names, Player's Numbers\n";
	cout << "Finally you will need the Points Scored by Players.\n\n\n";
	for (index = 0; index < NUM_PLAYERS; index++)
	{
		cout << "Please enter the Player's Name: ";
		cin.getline(players[index].name, 50);
		cout << "Please enter the Player's Number: ";
		(cin >> players[index].playNum).get();

		//To test my values for zero, negative
		while (players[index].playNum <= 0)
		{
			cout << "Zero or negative numbers not allowed\n";
			cout << "Please enter the Player's Number: ";
			(cin >> players[index].playNum).get();

		}
		cout << "Please enter the Points Scored by the Player: ";
		(cin >> players[index].Points).get();

		//To test my values for zero, negative.
		while (players[index].Points < 0)
		{
			cout << "Zero or negative numbers not allowed\n";
			cout << "Please enter the Points Scored by the Player: ";
			(cin >> players[index].Points).get();
		}
		cout << endl << endl;
	}
	return;
}
int  getTotalPoints(Player[], int)
{
	int index;
	int total = 0;
	//Calculate the total points
	for (index = 0; index < NUM_PLAYERS; index++)
	{
		total += players[index].Points;
	}
		int TotalPoints(int *, int);
	
	return total;
}
void showInfo(Player)
{
	int TotalPoints = 0;
	int index = 0;
	//Display the players data
	cout << "Here is the players data:\n\n";
	cout << "    Name    Number    Score	\n";
	cout << "--------------------------------\n";

	for (index = 0; index < NUM_PLAYERS; index++)
	{
		cout << setw(8) << players[index].name;
		cout << setw(8) << players[index].playNum;
		cout << setw(8) << players[index].Points << endl;
                TotalPoints +=players[index].Points;
	}
//Display the results of the total points.
	cout << "\n\nThe total of points scored by the team are: ";
	cout << TotalPoints << endl;

	//To get the player with most points

	int max = players[0].Points;
	int maxIndex = 0;
	for (int index = 0; index < NUM_PLAYERS; index++)
	{
		if (players[index].Points > max)
		{
			max = players[index].Points;
			maxIndex = index;
                        cout<<maxIndex<<endl;
		}
	
	}
	cout << "highest score by: " << players[maxIndex].name << " number: " << players[maxIndex].playNum << endl;
	return;
}

