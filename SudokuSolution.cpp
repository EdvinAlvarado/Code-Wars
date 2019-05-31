//https://www.codewars.com/kata/sudoku-solution-validator/train/cpp
#include <iostream>
#include <set>
using namespace std;

std::set<int> miniGridSet(unsigned int board[9][9],int i,int j) {
	
	std::set<int> returnSet;
	for (int x = i; x < i+3; x++) {
		for (int y = j; y < j+3; y++) {
			returnSet.insert(board[y][x]);
		}
	}
	return returnSet;
}

bool validSolution(unsigned int board[9][9]){

	std::set<int> rowset, colset;

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (board[y][x] == 0) {	return false;} 
			rowset.insert(board[y][x]);
			colset.insert(board[x][y]);
		}
 		// Checks all rows
		if (rowset.size() != 9) {return false;}
		rowset.clear();
		// Checks all cols
		if (colset.size() != 9) {return false;}
		colset.clear();
	}

	std::set<int> limit = {0, 3, 6};
	for (auto i = limit.begin(); i != limit.end(); i++) {
		for (auto j = limit.begin(); j != limit.end(); j++) {
			std::set<int> gridset = miniGridSet(board, *i, *j);
			if (gridset.size() != 9) {return false;}
		}
	}
	return true;
}

int main() {
	unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}}; 

	bool passed = validSolution(example1);
	std::cout << passed << std::endl;
}