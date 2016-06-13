#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "Basketball_Rogers.h"

//Prototipos
void random(void);    //Random number generator

int main(void)
{
	int i;    //For loop counter
	int team1points, team2points = 0;    //The points for each team

	//Seed the random number generator
	random();

	//Create pointer to Team object
	Team * newteam[2];

	//Create teams
	for (i = 0; i < 2; i++)
	{
		newteam[i] = new Team();
	}//for

	//Play the game!
	//Team1 starts with the ball
	for (i = 0; i < 120; i++)
	{
		if (i % 2 == 0)
		{
			//Team 1's shot
			newteam[i]->Play();
		}
		else
		{
			//Team 2's shot
			newteam[i]->Play();
		}

		/*
		if (i == 30 || i == 60 || i == 90 || i == 120)
		{
			team1points = newteam[0]->sendpoints();
			team2points = newteam[1]->sendpoints();

			if (team1points > team2points)
			{
				newteam[0]->sendteamname();
				cout << " leads " << team1points << " to " << team2points;
			}
			if (team2points > team1points)
			{
				newteam[1]->sendteamname();
				cout << " leads " << team2points << " to " << team2points;
			}
			if (team1points == team2points)
			{
				cout << "The game is tied " << team1points << " to " << team2points;
			}
			
			cout << endl << "Press any key to continue the game...";
			getchar();
		}//if
		*/
	}//for
	

	

	return 0;
}

//random - Random number generator
void random(void)
{
	int i;    // Loop counter
    
	// Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i<rand(); i++)
		rand();
}