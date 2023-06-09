#include <iostream>
#include <vector>
#include "Connect4.h"
#include "functions.h"

using namespace std;
using namespace connectFour;

//renders the board for the players. by Sam
vector<vector<char>> renderBoard(vector<vector<char>> board) {
    for (int i = 0; i < 8; i++) {
        cout << endl;
    }
    cout << "--1---2---3---4---5---6---7--" << endl;
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

//Checks for the different wins that occur in connect four. By Sam
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
    //back slash : \ checks
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

//Checks to see if there's a draw in the game. By Caleb
bool checkDraw(vector<vector<char>> board) {
    //Looks to see if every spot in the top row is filled
    for (int col = 0; col < 7; col++) {
        if (board[col][0] == char(32)) {
            //Returns if there isn't a draw
            return false;
        }
    }

    //Returns if there's a draw
    return true;
}

//Makes sure the player's move is legal. By Caleb
bool legalMove(int choice, vector<vector<char>> board) {
    choice--;
    //Checks if the top of the column is already filled
    if (board[choice][0] != char(32)) {
        //Returns illegal move
        return false;
    }

    //Returns legal move
    return true;
}

//Places player one's piece based on their input. By Sam
vector<vector<char>> playerMoveOne(int choice, vector<vector<char>> board) {
    //Places the player's piece in the most bottom row in the selected column
    for (int i = 5; i >= 0; i--) {
        if (board[choice][i] == char(32)) {
            board[choice][i] = char(88);
            //Returns the board with the move
            return board;
        }
    }

    //Returns the board without the move
    return board;
}

//Places player two's piece based on their input. By Caleb
vector<vector<char>> playerMoveTwo(int choice, vector<vector<char>> board) {
    //Places the player's piece in the most bottom row in the selected column
    for (int i = 5; i >= 0; i--) {
        if (board[choice][i] == char(32)) {
            board[choice][i] = char(79);
            //Returns the board with the move
            return board;
        }
    }

    //Returns the board without the move
    return board;
}

//AI for single player connect four. By Caleb
//Stops winning moves for the player
//Looks for winning moves for itself
//Makes a greedy move if there are no winning moves for either player
vector<vector<char>> AIMove(vector<vector<char>> board) {
    int choice;
    bool foundMove = false;

    // Check for winning move for computer
    for (int col = 0; col < 7 && !foundMove; col++) {
        vector<vector<char>> tempBoard = board;
        for (int row = 5; row >= 0; row--) {
            if (tempBoard[col][row] == char(32)) {
                tempBoard[col][row] = char(88);
                if (checkWinner(tempBoard)) {
                    choice = col;
                    foundMove = true;
                    break;
                }
                tempBoard[col][row] = char(32);
                break;
            }
        }
    }

    // Check for winning move for player
    if (!foundMove) {
        for (int col = 0; col < 7 && !foundMove; col++) {
            vector<vector<char>> tempBoard = board;
            for (int row = 5; row >= 0; row--) {
                if (tempBoard[col][row] == char(32)) {
                    tempBoard[col][row] = char(79);
                    if (checkWinner(tempBoard)) {
                        choice = col;
                        foundMove = true;
                        break;
                    }
                    tempBoard[col][row] = char(32);
                    break;
                }
            }
        }
    }

    // Greedy move - choose first available slot in center column. By both members
    if (!foundMove) {
        choice = rand();
        if (choice % 10 == 0) {
            choice = 3;
        }
        else if (choice % 9 == 0) {
            choice = 2;
        }
        else if (choice % 8 == 0) {
            choice = 4;
        }
        else if (choice % 7 == 0) {
            choice = 3;
        }
        else if (choice % 6 == 0) {
            choice = 2;
        }
        else if (choice % 5 == 0) {
            choice = 4;
        }
        else if (choice % 4 == 0) {
            choice = 1;
        }
        else if (choice % 3 == 0) {
            choice = 5;
        }
        else if (choice % 2 == 0) {
            choice = 0;
        }
        else if (choice % 1 == 0) {
            choice = 6;
        }
    }

    //Checks to see if the column is full
    while (board[choice][0] != char(32)) {
        choice = rand() % 7; // Choose a new column
    }

    // Make the move and return the updated board
    for (int row = 5; row >= 0; row--) {
        if (board[choice][row] == char(32)) {
            board[choice][row] = char(79);
            break;
        }
    }

    //Returns the board with the AI move
    return board;
}