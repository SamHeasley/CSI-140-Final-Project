#include <iostream>
#include <vector>

using namespace std;

vector<int> renderBoard() {

}

int playerMove(int choice) {

}

int aiMove() {

}

bool checkWinner() {

	return false;
}

int main() {
	bool winner = false;

	int playerChoice;

	while (!winner) {
		renderBoard();

		cout << "Pick a column: ";
		cin >> playerChoice;

		playerMove(playerChoice);

		winner = checkWinner();
	}

	return 0;
}
