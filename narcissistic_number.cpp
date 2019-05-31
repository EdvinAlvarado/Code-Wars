#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>

using namespace std;

bool narcissistic( int value ) {
	cout << "value: " << value << endl;
	string strvalue = to_string(value);
	std::vector<int> numvec;
	for (char& n: strvalue) {
		// cout << "digit " << (int)n -(int)'0'<< " "  << endl;  
		numvec.push_back((int) n - (int)'0'); 
	}
	for (int i = 1; i <= 10; i++) {
		int compare_value = 0; //std::accumulate(numvec.begin(), numvec.end(), 0);
		for (const auto& d: numvec) {
			compare_value += pow(d, i);
			cout << d << "^" << i << " + ";
		}

		cout << "= " << compare_value;
		if (compare_value == value) {
			cout << " true" << endl;
			return true;
			break;
		} else if (compare_value > value) {
			cout << " false" << endl;
			return false;
			break;
		}
		cout << endl;
	}
}

int main() {
	bool x = narcissistic(12);
	cout << endl << "? " << x << endl;
}