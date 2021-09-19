// https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/solutions/cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::vector<int> snail(std::vector<std::vector<int>> array) {

	std::vector<std::vector<int>> A(array);
	std::vector<int> snailvec = {};	
	size_t total_steps = 2* A.size() - 1;
	unsigned int path = 0;
	
	for (int step = 0; step < total_steps; step++) {

		// See how the array changes.
		for (auto row = A.begin(); row != A.end(); row++) {
			for (auto element = row->begin(); element != row->end(); element++) {
				cout << *element <<  "\t";
			}
			cout << endl;
		}
		cout << endl;

		if (path == 0) {
			// for (auto it = A[0].begin(); it != A[0].end(); it++) {
			// 	snailvec.push_back(*it);
			// }
			snailvec.insert(snailvec.end(), A[0].begin(), A[0].end());
			A.erase(A.begin());
		} else if (path == 1) {
			for (auto row = A.begin(); row != A.end(); row++) {
				snailvec.push_back(row->at(row->size()-1));
				row->erase(row->begin() + row->size()-1);
			}
		} else if (path == 2) {
			// for (auto it = A[A.size()-1].begin(); it != A[A.size()-1].end(); it++) {
			// 	temprev.push_back(*it);
			// }
			snailvec.insert(snailvec.end(), A[A.size()-1].rbegin(), A[A.size()-1].rend());
			A.erase(A.end() - 1);
		} else if (path == 3) {
			for (auto row = A.rbegin(); row != A.rend(); row++) {
				snailvec.push_back(row->at(0));
				row->erase(row->begin());
			}
		}		

		path++;
		if (path == 4) {
			path = 0;
		}
	}
	return snailvec;
}

int main() {
	// std::vector<std::vector<int>> arr = {{1,2,3}, {8,9,4}, {7,6,5}};
	std::vector<std::vector<int>> arr = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
	std::vector<int> snailed = snail(arr);
	for (int& n: snailed) {
		std::cout << n << " ";
	}
	cout << endl;
}