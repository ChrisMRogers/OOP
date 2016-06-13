/*
Chris Rogers
June 12th (Cutting it close)
BingoBongo_Rogers2
This program asks the user for a number of bingo cards to play and searches through each card, returning how many numbers
needed to be called for 1 card to reach bingo
*/

#include <iostream>
#include <Windows.h>
#include <time.h>
#include "BingoBongo_Rogers2.h"

//Prototypes
void random(void);    //Seeds the random number generator

using namespace std;

int main(void)
{
	int i, ii;      //For loop counter
	int howmany;    //Howmany cards to play
	int callednum;  //The number being "Called" (to be checked on each bingo card)
	int numturns;    //An array containing how many turns each amount of cards took to find bingo on average
	int avgturns[25];
					
	//Seed the random number generator	
	random();

	//Create pointer array to card object
	Card * ptrCard[25];

	//Set numturns
	for (i = 0; i < 25; i++)
		avgturns[i] = 0;
	
	//Ask the user for howmany Cards to play
	cout << "How many cards would you like to play?: ";
	cin >> howmany;

	//Create Card objects
	for (i = 0; i < howmany; i++)
	{
		ptrCard[i] = new Card();
	}//for

	//Find bingo on each card
	for (i = 1; i <= howmany; i++)
	{
		numturns = 1;
		//Run games 100 times
		for (ii = 0; ii < 100; ii++)
		{
			
			//Generate numbers until bingo is found on the card
			do
			{
				//Increase number of turns
				numturns++;

				//Generate number to be called
				callednum = rand() % 75 + 1;

				//Check each card for callednum
				ptrCard[i]->FindNum(callednum);

			} while (ptrCard[i--]->Bingo() != true);
		}//for
		//Calculate avg turns
		avgturns[i] = numturns / i;
		//Output avg number of turns needed
		cout << endl << "For " << i << " turns, " << avgturns[i] << " turns were needed." << endl;

	}//for

	return 0;
}//main

//Random number generator
void random(void)
{
	int i;    // Loop counter

	// Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i<rand(); i++)
		rand();

}//random