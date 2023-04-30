#ifndef FINALPROJECT_FUNCTIONS_H
#define FINALPROJECT_FUNCTIONS_H

#include <vector>

std::vector<std::vector<char>> renderBoard(std::vector<std::vector<char>> board);
bool checkWinner(std::vector<std::vector<char>> board);
bool checkDraw(std::vector<std::vector<char>> board);
bool legalMove(int choice, std::vector<std::vector<char>> board);
std::vector<std::vector<char>> playerMoveOne(int choice, std::vector<std::vector<char>> board);
std::vector<std::vector<char>> playerMoveTwo(int choice, std::vector<std::vector<char>> board);
std::vector<std::vector<char>> AIMove(std::vector<std::vector<char>> board);


#endif //FINALPROJECT_FUNCTIONS_H
