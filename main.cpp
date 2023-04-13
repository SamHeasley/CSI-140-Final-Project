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

int aiMove() {
	//professor recommended "Monte carlo tree search"
	return 0;
}

bool checkWinner() {

	return false;
}

int main() {
	bool winner = false;

	char empty = 32;
	char player = 88;
	char ai = 79;

	vector<vector<char>> board = vector<vector<char>>(7, vector<char>(6, empty));

	int playerChoice;

	while (!winner) {
		renderBoard(board);

		cout << "Pick a column(1-7): ";
		cin >> playerChoice;
		playerChoice--;

		board = playerMove(playerChoice, board);

		winner = checkWinner();
	}

	return 0;
}
