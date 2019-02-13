#ifndef BOARD_H
#define BOARD_H

#include <iostream>


using namespace std;


//board class holds the board functions and the board state

class Board {


	int winif;


public:

	//Variables
	char board[3][3] = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};
	int space;      //Human chosen space
	int choices[9] = { 0,0,0,0,0,0,0,0,0 };


	//Functions
															//Holding the previous choices
	int makeboard() {
		cout << "_____________" << endl;
		cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
		cout << "|___|___|___|" << endl;
		cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
		cout << "|___|___|___|" << endl;
		cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
		cout << "|___|___|___|" << endl;

		return 0;
	}

	int change(int space, char letter) {
		int item = 0;                            //var item is a bool for if the human has correctly chosen a space


		while (item == 0) {

			if (!(cin >> space)) {                     //checks for non ints

				cerr << "Try again." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			else if (choices[space - 1] != space) {

				item = 1;
				choices[space - 1] = space;

				if (space == 1) {
					board[0][0] = letter;
					break;
				}
				else if (space == 2) {
					board[0][1] = letter;
					break;
				}
				else if (space == 3) {
					board[0][2] = letter;
					break;
				}
				else if (space == 4) {
					board[1][0] = letter;
					break;
				}
				else if (space == 5) {
					board[1][1] = letter;
					break;
				}
				else if (space == 6) {
					board[1][2] = letter;
					break;
				}
				else if (space == 7) {
					board[2][0] = letter;
					break;
				}
				else if (space == 8) {
					board[2][1] = letter;
					break;
				}
				else if (space == 9) {
					board[2][2] = letter;
					break;
				}
				else {
					cout << "Invalid Input.";

				}
			}
			else {
				cout << "That space is taken.  Choose a different space." << endl;

			}
		}

		return 0;
	}

	int compchange(char letter) {
		int citem = 0;                    //var citem is a bool for if the comp has correctly chosen a space
		int cspace;
		

		while (citem != 1) {

			
			if (board[0][1] == 'O' && board[0][2] == 'O' && board[0][0] != 'X') {
				cspace = 1;
			}
			else if (board[1][0] == 'O' && board[2][0] == 'O' && board[0][0] != 'X') {
				cspace = 1;
			}
			else if (board[1][1] == 'O' && board[2][2] == 'O' && board[0][0] != 'X') {
				cspace = 1;
			}
			else if (board[0][0] == 'O' && board[0][2] == 'O' && board[0][1] != 'X') {
				cspace = 2;
			}
			else if (board[1][1] == 'O' && board[2][1] == 'O' && board[0][1] != 'X') {
				cspace = 2;
			}
			else if (board[1][2] == 'O' && board[2][2] == 'O' && board[0][2] != 'X') {
				cspace = 3;
			}
			else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] != 'X') {
				cspace = 3;
			}
			else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] != 'X') {
				cspace = 3;
			}
			else if (board[1][1] == 'O' && board[1][2] == 'O' && board[1][0] != 'X') {
				cspace = 4;
			}
			else if (board[0][0] == 'O' && board[2][0] == 'O' && board[1][0] != 'X') {
				cspace = 4;
			}
			else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] != 'X') {
				cspace = 6;
			}
			else if (board[0][2] == 'O' && board[2][2] == 'O' && board[1][2] != 'X') {
				cspace = 6;
			}
			else if (board[2][1] == 'O' && board[2][2] == 'O' && board[2][0] != 'X') {
				cspace = 7;
			}
			else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] != 'X') {
				cspace = 7;
			}
			else if (board[1][1] == 'O' && board[0][2] == 'O' && board[2][0] != 'X') {
				cspace = 7;
			}
			else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] != 'X') {
				cspace = 8;
			}
			else if (board[2][0] == 'O' && board[2][2] == 'O' && board[2][1] != 'X') {
				cspace = 8;
			}
			else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] != 'X') {
				cspace = 9;
			}
			else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] != 'X') {
				cspace = 9;
			}
			else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] != 'X') {
				cspace = 9;
			}
			else {
				cspace = (rand() % 9 + 1);               //Choosing a random space
			}
								
			


			if (choices[cspace - 1] == 0) {

				citem = 1;
				choices[cspace - 1] = cspace;


				if (cspace == 1) {
					board[0][0] = letter;

				}
				else if (cspace == 2) {
					board[0][1] = letter;

				}
				else if (cspace == 3) {
					board[0][2] = letter;

				}
				else if (cspace == 4) {
					board[1][0] = letter;

				}
				else if (cspace == 5) {
					board[1][1] = letter;

				}
				else if (cspace == 6) {
					board[1][2] = letter;

				}
				else if (cspace == 7) {
					board[2][0] = letter;

				}
				else if (cspace == 8) {
					board[2][1] = letter;

				}
				else if (cspace == 9) {
					board[2][2] = letter;

				}
				else {
					cout << "What happened?" << endl;

				}
			}
			else {
				cout << "Space failed" << endl;
			}
		}





		return citem;
	}

	int win() {


		char let[2] = { 'X','O' };
		int i = 0;

		for (let[i]; i < 2; i++) {
			if (board[0][0] == let[i] && board[0][1] == let[i] && board[0][2] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;

			}
			else if (board[1][0] == let[i] && board[1][1] == let[i] && board[1][2] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;
			}
			else if (board[2][0] == let[i] && board[2][1] == let[i] && board[2][2] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;
			}
			else if (board[0][0] == let[i] && board[1][0] == let[i] && board[2][0] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;
			}
			else if (board[0][1] == let[i] && board[1][1] == let[i] && board[2][1] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;
			}
			else if (board[0][2] == let[i] && board[1][2] == let[i] && board[2][2] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;
			}
			else if (board[0][0] == let[i] && board[1][1] == let[i] && board[2][2] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;
			}
			else if (board[2][0] == let[i] && board[1][1] == let[i] && board[0][2] == let[i]) {
				cout << let[i] << "'s win!" << endl;
				winif = 1;
			}

		}
		return winif;
	}				//Checks for winning, changes winif variable

	int getwinif() {
		return winif;
	}

	int stalemate() {
		if (choices[0] != 0
			&& choices[1] != 0
			&& choices[2] != 0
			&& choices[3] != 0
			&& choices[4] != 0
			&& choices[5] != 0
			&& choices[6] != 0
			&& choices[7] != 0
			&& choices[8] != 0
			&& choices[9] != 0) {
			return 1;
		}
	}

};


#endif

