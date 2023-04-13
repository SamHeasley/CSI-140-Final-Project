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

bool checkWinner() {

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
            playerChoice--;

            board = playerMove(playerChoice, board);

		//check if the player won
            winner = checkWinner();
            playerTurn = false;
        }
        else if (playerTurn == false){
            renderBoard(board);

            //Makes a random move for the easy AI
            int aiEasyChoice = rand() % 7;
            board = aiEasyMove(aiEasyChoice, board);

            winner = checkWinner();
            playerTurn = true;
        }
	}

	return 0;
}
