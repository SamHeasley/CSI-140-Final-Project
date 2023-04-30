#include <iostream>
#include <vector>
#include "Connect4.h"
#include "functions.h"

using namespace std;
using namespace connectFour;

//By both members
int main() {
    connectFourHeader header;

    bool winner = header.winner;
    bool playerTurn = header.playerTurn;
    bool validOption;

    vector<vector<char>> board = header.board;

    int playerChoice;
    int gamemode;

    cout << "Welcome to C++ Connect Four" << endl << "Type 1 to play the computer. Type 2 to play against another player.  " << endl;
    cin >> gamemode;


    //Gamemode One: Player V.S. Computer
    while (!winner && gamemode == 1) {
        srand(time(NULL));
        if (playerTurn == true) {

            validOption = false;

            //Makes sure choice was a valid option
            while (!validOption) {
                renderBoard(board);
                cout << "Pick a column(1-7): ";
                cin >> playerChoice;
                if (playerChoice > 0 && playerChoice < 8) {
                    //Makes sure the column isn't full
                    if (legalMove(playerChoice, board) == true) {
                        playerChoice--;
                        validOption = true;
                    }
                    else {
                        cout << "NOT A VALID MOVE" << endl;
                    }
                }
                else {
                    cout << "NOT A VALID OPTION" << endl;
                }
            }

            //Adds new move to the board
            board = playerMoveOne(playerChoice, board);

            //Looks for a draw if no more moves can be made
            if (checkDraw(board)) {
                cout << "The game is a draw!" << endl;
                return 0;
            }

            //Looks to see if there's a winner
            if (checkWinner(board)) {
                winner = checkWinner(board);
            }

            //Switches turn to the other player
            playerTurn = false;
        }
        else if (playerTurn == false) {
            renderBoard(board);

            //Has the computer make a move
            board = AIMove(board);

            //Looks for a draw if no more moves can be made
            if (checkDraw(board)) {
                cout << "The game is a draw!" << endl;
                return 0;
            }

            //Looks to see if there's a winner
            if (checkWinner(board)) {
                winner = checkWinner(board);
            }

            //Switches turn to the other player
            playerTurn = true;
        }
    }
    //Gamemode Two: Player V.S. Player
    while (!winner && gamemode == 2) {
        if (playerTurn == true) {
            validOption = false;

            //Makes sure choice was a valid option
            while (!validOption) {
                renderBoard(board);
                cout << "P1: Pick a column(1-7): ";
                cin >> playerChoice;
                if (playerChoice > 0 && playerChoice < 8) {
                    //Makes sure the column isn't full
                    if (legalMove(playerChoice, board) == true) {
                        playerChoice--;
                        validOption = true;
                    }
                    else {
                        cout << "NOT A VALID MOVE" << endl;
                    }
                }
                else {
                    cout << "NOT A VALID OPTION" << endl;
                }
            }

            //Adds new move to the board
            board = playerMoveOne(playerChoice, board);

            //Looks for a draw if no more moves can be made
            if (checkDraw(board)) {
                cout << "The game is a draw!" << endl;
                return 0;
            }

            //Looks to see if there's a winner
            if (checkWinner(board)) {
                winner = checkWinner(board);
            }

            //Switches turn to the other player
            playerTurn = false;
        }
        else if (playerTurn == false) {
            validOption = false;

            //Makes sure choice was a valid option
            while (!validOption) {
                renderBoard(board);
                cout << "P2: Pick a column(1-7): ";
                cin >> playerChoice;
                if (playerChoice > 0 && playerChoice < 8) {
                    //Makes sure the column isn't full
                    if (legalMove(playerChoice, board) == true) {
                        playerChoice--;
                        validOption = true;
                    }
                    else {
                        cout << "NOT A VALID MOVE" << endl;
                    }
                }
                else {
                    cout << "NOT A VALID OPTION" << endl;
                }
            }

            //Adds new move to the board
            board = playerMoveTwo(playerChoice, board);

            //Looks for a draw if no more moves can be made
            if (checkDraw(board)) {
                cout << "The game is a draw!" << endl;
                return 0;
            }

            //Looks to see if there's a winner
            if (checkWinner(board)) {
                winner = checkWinner(board);
            }

            //Switches turn to the other player
            playerTurn = true;
        }
    }

    renderBoard(board);
    cout << "There is a winner!" << endl;
    return 0;
}
