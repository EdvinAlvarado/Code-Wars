// https://www.codewars.com/kata/52bb6539a4cf1b12d90005b7
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int diagonal_adjacent(vector< vector<int> > &matrix, int row, int col) {
	int adj_val;
	if (row == 0) {
		if (col == 0) {
			adj_val = matrix[0][1] + matrix[1][0] + matrix[1][1];
			// cout<< "top left" << endl;
		} else if (col == 10 - 1) {
			adj_val =  matrix[0][col - 1] + matrix[1][col] + matrix[1][col - 1];
			// cout<< "top right" << endl;
		} else {
			adj_val =  matrix[0][col - 1] + matrix[0][col + 1] + matrix[1][col] + matrix[1][col - 1] + matrix[1][col + 1];
			// cout<< "top" << endl;
		}
	} else if (row == 10 - 1) {
		if (col == 0) {
			adj_val = matrix[row - 1][0] + matrix[row][1] + matrix[row - 1][1];
			// cout << "bottom left" << endl;
		} else if (col == 10 - 1) {
			adj_val = matrix[row][col - 1] + matrix[row - 1][col] + matrix[row - 1][col - 1];
			// cout << "bottom right" << endl;
		} else {
			adj_val = matrix[row][col - 1] + matrix[row][col + 1] + matrix[row - 1][col] + matrix[row - 1][col - 1] + matrix[row - 1][col + 1];
			// cout << "bottom" << endl;
		}
	} else if (col == 0) {
		adj_val = matrix[row - 1][0] + matrix[row + 1][0] + matrix[row][1] + matrix[row - 1][1] + matrix[row + 1][1];
		// cout << "left" << endl;
	} else if (col == 10 - 1) {
		adj_val = matrix[row - 1][col] + matrix[row + 1][col] + matrix[row][col - 1] + matrix[row - 1][col - 1] + matrix[row + 1][col -1];
		// cout << "right" << endl;
	} else {
		adj_val = matrix[row][col - 1] + matrix[row][col + 1] + matrix[row - 1][col] + matrix[row + 1][col] + matrix[row - 1][col - 1] + matrix[row - 1][col + 1] + matrix[row + 1][col + 1] + matrix[row + 1][col - 1];
		// cout << "middle" << endl;
	}
	return adj_val;
}

void prettyPrint(array <array<short int, 10>, 10> &matrix) {
	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
			if (matrix[y][x] == -1) {
				cout << "  ";
			} else {
				cout << matrix[y][x] << " ";
			}
		}
		cout << endl;
	}
}

bool validate_battlefield(vector< vector<int> > field) {

	array <array<short int, 10>, 10> bmap;
  
	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
			if (field[y][x] == 1) {
				bmap[y][x] = diagonal_adjacent(field, y, x);
				if (diagonal_adjacent(field, y, x) > 2) {
					return false;
				}
			} else {
				bmap[y][x] = -1;
			}			
		}
	}
	prettyPrint(bmap);

	short int zero_count = 0;
	short int one_count = 0;
	short int two_count = 0;
	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
		
			if (bmap[y][x] == 0) {
				zero_count++;
			} else if (bmap[y][x] == 1) {
				one_count++;
			} else if (bmap[y][x] == 2) {
				two_count++;
			}
		}
	}	

	if ((zero_count == 4) && (one_count == 12) && (two_count == 4)) {
		return true;
	} else {
		return false;
	}

}

int main() {
	vector< vector<int> > field{
		vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
		vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
		vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
	
	cout << validate_battlefield(field) << endl;

}