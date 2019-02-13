#include <iostream>
#include <ctime>


#include "board.cpp"

using namespace std;

int main() {

	int first;
	srand(time(NULL));
	Board game;

	game.makeboard();

	std::cout << "Tic Tac Toe vs. Tyson the Bot." << endl;
	std::cout << "Who goes first?" << endl;
	std::cout << "Type the number:" << endl;
	std::cout << "1) Player." << endl;
	std::cout << "2) Computer" << endl;
	cin >> first;

	if (first == 1) {
		while (game.getwinif() != 1) {


			cout << "O's turn." << endl;
			game.change(game.space, 'O');

			game.makeboard();
			game.win();

			

			
			if (game.stalemate() == 1) {
				cout << "Stalemate." << endl;
				break;
			}

			if (game.getwinif() == 1) {
				game.makeboard();
				break;
			}

			game.compchange('X');

			//Computer move function doesn't take a space arg
								  //It is chosen during the function after it is called
			game.makeboard();
			game.win();
			if (game.stalemate() == 1) {
				cout << "Stalemate." << endl;
				break;
			}

		}
	}


	else if (first == 2) {


		while (game.getwinif() != 1) {

			game.compchange('X');

			game.makeboard();
			game.win();
			if (game.stalemate() == 1) {
				cout << "Stalemate." << endl;
				break;
			}
			if (game.getwinif() == 1) {
				game.makeboard();
				break;
			}

			cout << "O's turn." << endl;
			game.change(game.space, 'O');

			//Computer move function doesn't take a space arg
								  //It is chosen during the function after it is called
			game.makeboard();
			game.win();

		}

		cout << "Good Game.";

		
	}
	else {
		cout << "Invalid Input, goodbye.";
	}


	return 0;
}