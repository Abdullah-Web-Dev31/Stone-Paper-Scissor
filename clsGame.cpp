#pragma
#include <iostream>
using namespace std;

 class clsGame {

 public:

	 int ReadNumber(string msg = "Please eneter a posetave number? ") {
		 short input;
		 cout << msg;
		 cin >> input;
		 while (input <= 0) {
			 cout << "\n Wron input\n";
			 cout << msg;
			 cin >> input;

		 }
		 return input;
	 }
	 enum  enOptions { Stone = 1, Paper = 2, Scissor = 3 };

	  enOptions ChooisingOption() {
		 short op;
		 cout << "\nYour Choice : [1]:Stone, [2]:Paper, [3]:Scissor ?";
		 cin >> op;



		 while (op <= 0 || op > 3) {
			 cout << "\nWrong Choise ";
			 cout << "\nYour Choice : [1]:Stone, [2]:Paper, [3]:Scissor ?";
			 cin >> op;

		 }
		 return (enOptions)op;
	 }
	  
	  enum enWinner{Player=1,Computer=2,Draw=3};
	  string WinnerString(enWinner winner) {
		  switch (winner) {
		  case enWinner::Player:
			  return "Player";
		  case enWinner::Computer:
			  return "Computer";
		  case enWinner::Draw:
			  return "Draw";
		  }
	  }


	  struct GameInfo
	  {
		  int GameRound;
		  int PlyearWonTime;
		  int ComputerWonTime;
		  int DrawTime;
		  int FinalWinner;
		  enWinner WhoWinner;
	  };

	  string OptionString(enOptions op)
	  {
		  switch (op) {
		  case Stone:
			  return "Stone";
		  case Paper:
			  return "Paper";
		  case Scissor:
			  return "Scissor";
		  }
	  }

	  enWinner Who_Win_In_Random(enOptions PlayerChoice, enOptions ComputerChoice) {

		  switch (PlayerChoice) {
		  case enOptions::Paper:
			  if (Computer == enOptions::Scissor)
				  return enWinner::Computer;
			  else if (Computer == enOptions::Stone)
				  return enWinner::Player;
			  else
				  return enWinner::Draw;

		  case enOptions::Scissor:

			  if (Computer == enOptions::Scissor)
				  return enWinner::Draw;
			  else if (Computer == enOptions::Stone)
				  return enWinner::Computer;
			  else
				  return enWinner::Player;

		  case enOptions::Stone:


			  if (Computer == enOptions::Scissor)
				  return enWinner::Player;
			  else if (Computer == enOptions::Stone)
				  return enWinner::Draw;
			  else
				  return enWinner::Computer;

		  default:
			  return enWinner::Draw;				  

		  }
	  }

	  GameInfo stGameinfo;
	  struct containerInfoRound
	  {
		  int Round_Number;
		  enOptions player_Choice;
		  enOptions Computerr_Choice;
		  enWinner Who_Winner;
	  };
	  void PrintRoundInfo(containerInfoRound round_info) {

		  cout << "\n";
		  cout << "\n_____________Round [" <<round_info.Round_Number << "] ____________\n";

		  cout << "\nPlayer Choice : "<<OptionString(round_info.player_Choice);
		  cout << "\nComputer Choice : " << OptionString(round_info.Computerr_Choice);
		  cout << "\nRound Winner : " << WinnerString(round_info.Who_Winner);


		  cout << "\n\n___________________________________\n";


	  }

	  int RandomNumber(int from, int to)
	  {
		  int randNum = rand() % (to - from + 1) + from;
		  return randNum;
	  }

	  enOptions GetRandomComputerChoice() {
		  return (enOptions)RandomNumber(1, 3);
	  }

	  containerInfoRound GetRoundInfo(int roundnumber, enOptions player, enOptions computer, enWinner winner) {
		  containerInfoRound info;
		  info.Round_Number = roundnumber;
		  info.player_Choice = player;
		  info.Computerr_Choice = computer;
		  info.Who_Winner = winner;
		  return info;
	  }


	  }

};
