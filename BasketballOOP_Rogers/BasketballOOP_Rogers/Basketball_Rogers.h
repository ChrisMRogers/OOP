//Header
using namespace std;

class Player    //The Player object
{
public:
	Player();   //The Constructor for the player object
	~Player();  //The Deconstructor for the player object
int shotpct(int ii);    //Returns the shot percent for a given player
char Playername[25];    //The player's name
void shotstaken(int ii);      //Increases the amount of shots each player has taken
void shotsmade(int ii);       //Increases the amount of shots made by each player

private:
	float Pct3;             //Player's 3 Point shot percentage
	float Pct2;             //Player's 2 Point shot percentage
	float Pct1;             //Player's 1 Point shot percentage
	int Taken3point;        //Amount of 3 point shots taken by the player
	int Taken2point;        //Amount of 2 point shots taken by the player
	int Taken1point;        //Amount of 1 point shots taken by the player
	int Made3pt;            //Number of made 3 pointers
	int Made2pt;            //Number of made 2 pointers
	int Made1pt;            //Number of made 1 pointers
	
};

//Constructor
Player::Player()
{
	//Set values to 0
	Pct3, Pct2, Pct1 = 0;
	Taken3point, Taken2point, Taken1point = 0;
	Made3pt, Made2pt, Made1pt = 0;

	cout << "_________________________________________" << endl;
	cout << "Player name: ";
	cin.getline(Playername, 25, '\n');

	//Get point shot percentages
	cout << endl << "3 Point Percentage: ";
	cin >> Pct3;
	cout << endl << "2 Point Percentage: ";
	cin >> Pct2;
	cout << endl << "Free Throw Percentage: ";
	cin >> Pct1;
	cout << "_________________________________________" << endl << endl;
	cin.ignore();
}

Player::~Player()
{

}

int Player::shotpct(int ii)
{
	switch (ii)
	{
	case 1:
		return Pct1;
		break;
	case 2:
		return Pct2;
		break;
	case 3:
		return Pct3;
		break;
	}//switch

}//shotpct

void Player::shotstaken(int ii)
{
	switch (ii)
	{
	case 1: Taken1point++;
		break;
	case 2: Taken2point++;
		break;
	case 3: Taken3point++;
		break;
	}
}

void Player::shotsmade(int ii)
{
	switch (ii)
	{
	case 1: Made1pt++;
		break;
	case 2: Made2pt++;
		break;
	case 3: Made3pt++;
		break;

	}
}


class Team    //The team object
{
public:
	Team();  //The constructor for the team object
	~Team(); //The destructor for the team object
	void Play();  //What occurs on each play (15 for each team)
	int sendpoints();    //returns the amount of points each team has
	void sendteamname(); //Returns the team name

private:
	char Teamname[25];    //The team's name
	int points;    //Amount of points scored by the team
	Player * players[5];	
};

Team::Team()
{
	int i = 0;    //For loop counter
	

	cout << "Enter Team Name: ";
	cin.getline(Teamname, 25, '\n');

	//Create players
	for (i = 0; i < 5; i++)
	{
		players[i] = new Player();
	}//for

}

Team::~Team()
{

}

void Team::Play()
{
	int i = 0;   //for loop counter
	int ii = 0;  //for loop counter
	int playershotpct = 0;    //Shot pct for the given shot
	int shotchance = 0;    //The chance that the shot is made
	
	//Determine who shoots
	i = rand() % 5;
	switch (i)
	{
	case 0: //player[0] shoots
		//Determine what kind of shot is taken
		ii = rand() % 3 + 1;
		switch (ii)
		{
		case 1: //1 point shot taken
			//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				//Shot made
				points++;
				//Output play by play
				cout << players[i]->Playername << " made a freethrow!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed their freethrow!" << endl;
			}//else
			break;

		case 2: //2 point shot taken
			//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 2;
				//Output play by play
				cout << players[i]->Playername << " made a field goal!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed an open jumper!" << endl;
			}
			break;

		case 3: //3 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 3;
				//Output play by play
				cout << players[i]->Playername << " made a three pointer!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " airballs a 3!" << endl;
			}
			break;
		}//switch (ii)

	case 1: //player[0] shoots
			//Determine what kind of shot is taken
		ii = rand() % 3 + 1;
		switch (ii)
		{
		case 1: //1 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points++;
				//Output play by play
				cout << players[i]->Playername << " made a freethrow!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed their freethrow!" << endl;
			}//else
			break;

		case 2: //2 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 2;
				//Output play by play
				cout << players[i]->Playername << " made a field goal!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed an open jumper!" << endl;
			}
			break;

		case 3: //3 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 3;
				//Output play by play
				cout << players[i]->Playername << " made a three pointer!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " airballs a 3!" << endl;
			}
			break;
		}//switch (ii)

	case 2: //player[0] shoots
			//Determine what kind of shot is taken
		ii = rand() % 3 + 1;
		switch (ii)
		{
		case 1: //1 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points++;
				//Output play by play
				cout << players[i]->Playername << " made a freethrow!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed their freethrow!" << endl;
			}//else
			break;

		case 2: //2 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 2;
				//Output play by play
				cout << players[i]->Playername << " made a field goal!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed an open jumper!" << endl;
			}
			break;

		case 3: //3 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 3;
				//Output play by play
				cout << players[i]->Playername << " made a three pointer!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " airballs a 3!" << endl;
			}
			break;
		}//switch (ii)

	case 3: //player[0] shoots
			//Determine what kind of shot is taken
		ii = rand() % 3 + 1;
		switch (ii)
		{
		case 1: //1 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points++;
				//Output play by play
				cout << players[i]->Playername << " made a freethrow!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed their freethrow!" << endl;
			}//else
			break;

		case 2: //2 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 2;
				//Output play by play
				cout << players[i]->Playername << " made a field goal!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed an open jumper!" << endl;
			}
			break;

		case 3: //3 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 3;
				//Output play by play
				cout << players[i]->Playername << " made a three pointer!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " airballs a 3!" << endl;
			}
			break;
		}//switch (ii)

	case 4: //player[0] shoots
			//Determine what kind of shot is taken
		ii = rand() % 3 + 1;
		switch (ii)
		{
		case 1: //1 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points++;
				//Output play by play
				cout << players[i]->Playername << " made a freethrow!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed their freethrow!" << endl;
			}//else
			break;

		case 2: //2 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 2;
				//Output play by play
				cout << players[i]->Playername << " made a field goal!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " missed an open jumper!" << endl;
			}
			break;

		case 3: //3 point shot taken
				//Get the shot pct for freethrow
			playershotpct = players[i]->shotpct(ii);
			//Determine if shot is made
			shotchance = rand() % 100 + 1;
			if (shotchance >= playershotpct)
			{
				//Shot made
				players[i]->shotstaken(ii);
				players[i]->shotsmade(ii);
				points = points + 3;
				//Output play by play
				cout << players[i]->Playername << " made a three pointer!" << endl;
			}//if
			else
			{
				//Shot missed
				players[i]->shotstaken(ii);
				//Output play by play
				cout << players[i]->Playername << " airballs a 3!" << endl;
			}
			break;
		}//switch (ii)
	}//switch (i)

}//Play()

int Team::sendpoints()
{
	return points;
}

void Team::sendteamname()
{
	cout << Teamname;
}