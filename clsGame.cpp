#pragma
#include <iostream>
using namespace std;

 class clsGame {

 public:

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



	  struct GameInfo
	  {
		  int GameRound;
		  int PlyearWonTime;
		  int ComputerWonTime;
		  int DrawTime;
		  int FinalWinner;
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
			

};
