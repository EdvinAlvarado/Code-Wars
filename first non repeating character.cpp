#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

char first_non_repeating_letter(std::string word) {
	cout << "string: " << word << endl;
	std::map<char, std::vector<int>> indexmap;
	std::map<char, int> countmap;

	int counter = 0;
	for (char& c: word) { // fill out maps
		indexmap[c].push_back(counter);
		counter += 1;

		if (countmap.find(c) == countmap.end()) {
			countmap[c] = 1;
		} else {
			countmap[c] += 1;
		}
	}
	// cout << endl;
	cout << "-----------------" << endl; 

	// char& key = it->first;
	for (std::map<char, std::vector<int>>::iterator it = indexmap.begin(); it != indexmap.end(); ++it) {
		// character
		cout << it->first << "\t";
		// Counts
		cout << countmap[it->first] << "\t";
		// Vector
		std::vector<int>& value = it->second;
		cout << "[";
		for (int& valindex: value) {
			cout << valindex << ", ";
		}
		cout << "]" << endl;
	}
	
	char non_repeating_char;
	int min_index;
	for (std::map<char, int>::iterator itr = countmap.begin(); itr != countmap.end(); ++itr) {
		if (itr->second == 1) {
			cout << "itr " << itr->first << endl;
			if (non_repeating_char == 0) { // initial condition
				non_repeating_char = itr->first;
				min_index = indexmap[itr->first][0];
			} else if (min_index > indexmap[itr->first][0]) { // if next iteration went first than the former iteration
					min_index = indexmap[itr->first][0];
					non_repeating_char = itr->first;
			} 
		}
	}
	cout << endl;
	return non_repeating_char;
}


int main() {
	string cinword;
	cout << "word: ";
	cin >> cinword;
	cout << first_non_repeating_letter(cinword) << endl;
}