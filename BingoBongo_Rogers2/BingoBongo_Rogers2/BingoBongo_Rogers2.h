//This header file contains the object code for BingoBongo_Rogers2

enum spaceVal { number, freespace };

//Structure containing values for the square
struct squareVal
{
	spaceVal value;    //Whether the value of each square is a number or a freespace
	bool picked;       //Whether the number has been found/picked
	int num;           //The number on the square
};

//Card Object
class Card
{
public:
	Card();    //Constructor for the card object
	~Card();   //Destructor for the card object
	bool Bingo();       //Checks for bingo on the Card
	void FindNum(int);  //Finds the number (Sent from main) on the card and sets other values accordingly
	squareVal Squares[5][5];    //Each square on the bingo card
};

//Constructor
Card::Card()
{
	int i;    //For loop counter
	int ii;   //For loop counter

	//Set initial values of card
	//Set spaceVal
	for (i = 0; i <= 4; i++)
	{
		for (ii = 0; ii <= 4; ii++)
		{
			if (i == 2 && ii == 2)
			{
				//Set middle spot to freespace
				Squares[i][ii].value = freespace;
			}//if
			else
				Squares[i][ii].value = number;
		}//for
	}//for

	//Set picked
	for (i = 0; i <= 4; i++)
	{
		for (ii = 0; ii <= 4; ii++)
		{
			if (i == 2 && ii == 2)
			{
				//Set middle spot to picked
				Squares[i][ii].picked = true;
			}//if
			else
				Squares[i][ii].picked = false;
		}//for
	}//for

	//Set num
	for (i = 0; i <= 4; i++)
	{
		for (ii = 0; ii <= 4; ii++)
		{
			if (i == 2 && ii == 2)
			{
				//Set middle num to null
				Squares[i][ii].num = NULL;
			}//if
			else
				Squares[i][ii].num = -1;
		}//for
	}//for

	//Set values on each space
	//Set first column values
	for (i = 0; i <= 4; i++)
	{
		Squares[0][i].num = rand() % 15 + 1;		
	}		
	//Check for duplicate numbers			
	for (int i = 0; i < 5 - 1; i++)		
	{						
		for (int ii = i + 1; ii < 5; ii++)			
		{				
			if (Squares[0][i].num == Squares[0][ii].num)				
			{					
				Squares[0][i].num = rand() % 15 + 1;				
			}//if			
		}//for		
	}//for

	//Set Second column values
	for (i = 0; i <= 4; i++)
	{
		Squares[1][i].num = rand() % 15 + 16;
	}
	//Check for duplicate numbers			
	for (int i = 0; i < 5 - 1; i++)
	{			
		for (int ii = i + 1; ii < 5; ii++)
		{
			if (Squares[1][i].num == Squares[1][ii].num)
			{
				Squares[1][i].num = rand() % 15 + 16;
			}//if			
		}//for		
	}//for

	//Set third column values
	for (i = 0; i <= 4; i++)
	{
		Squares[2][i].num = rand() % 15 + 31;
	}
	Squares[2][2].num = NULL;
	//Check for duplicate numbers			
	for (int i = 0; i < 5 - 1; i++)
	{			
		for (int ii = i + 1; ii < 5; ii++)
		{
			if (Squares[2][i].num == Squares[2][ii].num)
			{
				Squares[2][i].num = rand() % 15 + 31;
			}//if			
		}//for		
	}//for

	 //Set fourth column values
	for (i = 0; i <= 4; i++)
	{
		Squares[3][i].num = rand() % 15 + 46;
	}
	//Check for duplicate numbers			
	for (int i = 0; i < 5 - 1; i++)
	{		
		for (int ii = i + 1; ii < 5; ii++)
		{
			if (Squares[3][i].num == Squares[0][ii].num)
			{
				Squares[3][i].num = rand() % 15 + 46;
			}//if			
		}//for		
	}//for

	 //Set Fifth column values
	for (i = 0; i <= 4; i++)
	{
		Squares[4][i].num = rand() % 15 + 61;
	}
	//Check for duplicate numbers			
	for (int i = 0; i < 5 - 1; i++)
	{		
		for (int ii = i + 1; ii < 5; ii++)
		{
			if (Squares[4][i].num == Squares[0][ii].num)
			{
				Squares[4][i].num = rand() % 15 + 61;
			}//if			
		}//for		
	}//for
}

Card::~Card()
{

}

//Finds number from mainline on the card
void Card::FindNum(int callednum)
{
	int i;    //For loop counter

	//Determine what callednum is and depending on value search a certain column for number
	if (callednum <= 15)
	{
		//Search array for callednum
		for (i = 0; i < 5; i++)
		{
			if (Squares[0][i].num == callednum)
				Squares[0][i].picked = true;
		}//for
	}//if
	if (callednum <= 30 && callednum > 15)
	{
		for (i = 0; i < 5; i++)
		{
			if (Squares[1][i].num == callednum)
				Squares[1][i].picked = true;
		}//for
	}//if
	if (callednum <= 45 && callednum > 30)
	{
		for (i = 0; i < 5; i++)
		{
			if (Squares[2][i].num == callednum)
				Squares[2][i].picked = true;
		}//for
	}//if
	if (callednum <= 60 && callednum > 45)
	{
		for (i = 0; i < 5; i++)
		{
			if (Squares[3][i].num == callednum)
				Squares[3][i].picked = true;
		}//for
	}//if
	std::cout << "You've got this far";
	if (callednum <= 75 && callednum > 60)
	{
		for (i = 0; i < 5; i++)
		{
			if (Squares[4][i].num == callednum)
				Squares[4][i].picked = true;
		}//for
	}//if

	//Check for bingo
	Bingo();
}

bool Card::Bingo()
{
	//Vertical win
	if (Squares[0][0].picked == true && Squares[0][1].picked == true && Squares[0][2].picked == true && Squares[0][3].picked == true && Squares[0][4].picked == true)
		return true;
	else
		if (Squares[1][0].picked == true && Squares[1][1].picked == true && Squares[1][2].picked == true && Squares[1][3].picked == true && Squares[1][4].picked == true)
			return true;
		else
			if (Squares[2][0].picked == true && Squares[2][1].picked == true && Squares[2][2].picked == true && Squares[2][3].picked == true && Squares[2][4].picked == true)
				return true;
			else
				if (Squares[3][0].picked == true && Squares[3][1].picked == true && Squares[3][2].picked == true && Squares[3][3].picked == true && Squares[3][4].picked == true)
					return true;
				else
					if (Squares[4][0].picked == true && Squares[4][1].picked == true && Squares[4][2].picked == true && Squares[4][3].picked == true && Squares[4][4].picked == true)
						return true;
					else
						//Horizontal win
						if (Squares[0][0].picked == true && Squares[1][0].picked == true && Squares[2][0].picked == true && Squares[3][0].picked == true && Squares[4][0].picked == true)
							return true;
						else
							if (Squares[0][1].picked == true && Squares[1][1].picked == true && Squares[2][1].picked == true && Squares[3][1].picked == true && Squares[4][1].picked == true)
								return true;
							else
								if (Squares[0][2].picked == true && Squares[1][2].picked == true && Squares[2][2].picked == true && Squares[3][2].picked == true && Squares[4][2].picked == true)
									return true;
								else
									if (Squares[0][3].picked == true && Squares[1][3].picked == true && Squares[2][3].picked == true && Squares[3][3].picked == true && Squares[4][3].picked == true)
										return true;
									else
										if (Squares[0][0].picked == true && Squares[1][0].picked == true && Squares[2][0].picked == true && Squares[3][0].picked == true && Squares[4][0].picked == true)
											return true;
										else
											//Diagonal win
											if (Squares[0][0].picked == true && Squares[1][1].picked == true && Squares[2][2].picked == true && Squares[3][3].picked == true && Squares[4][4].picked == true)
												return true;
											else
												if (Squares[4][0].picked == true && Squares[3][1].picked == true && Squares[2][2].picked == true && Squares[1][3].picked == true && Squares[0][4].picked == true)
													return true;
												else
													return false;

}