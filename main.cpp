#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> renderBoard(vector<vector<char>> board) {
	for (int i = 0; i < 8; i++) {
		cout << endl;
	}
	for (int i = 0; i < 6; i++) {
		cout << "| ";
		for (int j = 0; j < 7; j++) {
			cout << board[j][i] << " | ";
		}
		cout << endl;
		cout << "-----------------------------" << endl;
	}

	return board;
}

vector<vector<char>> playerMove(int choice, vector<vector<char>> board) {
	for (int i = 5; i >= 0; i--) {
		if (board[choice][i] == char(32)) {
			board[choice][i] = char(88);
			return board;
		}
	}

	return board;
}

vector<vector<char>> aiEasyMove(int ranDecision, vector<vector<char>> board) {
	for (int i = 5; i >= 0; i--) {
		if (board[ranDecision][i] == char(32)) {
			board[ranDecision][i] = char(79);
			return board;
		}
	}

	return board;
}

int aiDifficultMove() {
	//professor recommended "Monte carlo tree search"
	return 0;
}

bool checkWinner(vector<vector<char>> board) {
	//vertical checks
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 7; col++) {
			if (board[col][row] == char(79) && board[col][row + 1] == char(79) && board[col][row + 2] == char(79) && board[col][row + 3] == char(79)) {
				return true;
			}
			if (board[col][row] == char(88) && board[col][row + 1] == char(88) && board[col][row + 2] == char(88) && board[col][row + 3] == char(88)) {
				return true;
			}
		}
	}
	//horizontal checks
	for (int row = 0; row < 6; row++) {
		for (int col = 0; col < 4; col++) {
			if (board[col][row] == char(79) && board[col + 1][row] == char(79) && board[col + 2][row] == char(79) && board[col + 3][row] == char(79)) {
				return true;
			}
			if (board[col][row] == char(88) && board[col + 1][row] == char(88) && board[col + 2][row] == char(88) && board[col + 3][row] == char(88)) {
				return true;
			}
		}
	}
	//forward slash : / checks
	for (int row = 3; row < 6; row++) {
		for (int col = 0; col < 4; col++) {
			if (board[col][row] == char(79) && board[col + 1][row - 1] == char(79) && board[col + 2][row - 2] == char(79) && board[col + 3][row - 3] == char(79)) {
				return true;
			}
			if (board[col][row] == char(88) && board[col + 1][row - 1] == char(88) && board[col + 2][row - 2] == char(88) && board[col + 3][row - 3] == char(88)) {
				return true;
			}
		}
	}
	//back slah : \ checks
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			if (board[col][row] == char(79) && board[col + 1][row + 1] == char(79) && board[col + 2][row + 2] == char(79) && board[col + 3][row + 3] == char(79)) {
				return true;
			}
			if (board[col][row] == char(88) && board[col + 1][row + 1] == char(88) && board[col + 2][row + 2] == char(88) && board[col + 3][row + 3] == char(88)) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	bool winner = false;
	bool playerTurn = true;

	char empty = 32;
	char player = 88;
	char ai = 79;

	vector<vector<char>> board = vector<vector<char>>(7, vector<char>(6, empty));

	int playerChoice;

	while (!winner) {
		if (playerTurn == true) {
			renderBoard(board);

			cout << "Pick a column(1-7): ";
			cin >> playerChoice;
			playerChoice--;

			board = playerMove(playerChoice, board);

			//check if the player won
			winner = checkWinner(board);
			playerTurn = false;
		}
		else if (playerTurn == false) {
			renderBoard(board);

			//Makes a random move for the easy AI
			int aiEasyChoice = rand() % 7;
			board = aiEasyMove(aiEasyChoice, board);
			cout << "AI chose" << aiEasyChoice << endl;

			winner = checkWinner(board);
			playerTurn = true;
		}
	}

	renderBoard(board);
	cout << "There is a winner!" << endl;
	return 0;
}
