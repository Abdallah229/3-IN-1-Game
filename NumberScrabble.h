#ifndef INC_3_IN_1_NUMBERSCRABBLE_H
#define INC_3_IN_1_NUMBERSCRABBLE_H
#include "Headers.h"

// Function to print a list of numbers
void Print_list(const std::vector<int>& numbers);

// Function to check if there is a winning combination of three numbers summing to 15
bool hasWinningCombination( std::vector<int>& nums);

// Function to validate player input and check if it is in the available list of numbers
void Is_Valid(int turn, int& num, std::vector<int>& numbers);

// Function to handle the game logic
std::string NumberScrabble();

#endif // INC_3_IN_1_NUMBERSCRABBLE_H
