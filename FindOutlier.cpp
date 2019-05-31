//You are given an array (which will have a length of at least 3, but could be very large) containing integers. The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.
#include <vector>
#include <iostream>

using namespace std;

// int FindOutlier(std::vector<int> arr) {
// 	int odd_counter = 0;
// 	std::vector<int> odd_v;
// 	for (const auto& n: arr) {
// 		bool odd_bool = n % 2;
// 		odd_counter += odd_bool;
// 		odd_v.push_back(odd_bool);
// 	}

// 	if (odd_counter > 1) { // mostly odd
// 		for (int i = 0; i < odd_v.size(); i++) {
// 			if (odd_v[i] == 0) {
// 				return arr[i];
// 			}
// 		}
// 	} else if (odd_counter == 1) { // mostly even
// 		for (int i = 0; i < odd_v.size(); i++) {
// 			if (odd_v[i] == 1) {
// 				return arr[i];
// 			}
// 		}
// 	} else {
// 		cerr << "ERROR";
// 	}
// }

int FindOutlier(std::vector<int> arr) {
	int evenCounter = 0;
	int oddCounter = 0;
	bool isEven;
	for (auto it = arr.begin(); it != arr.begin()+3; it++) {
		cout << "num " << *it << endl;
		*it % 2 == 0 ? evenCounter++ : oddCounter++;
		cout << "evenCounter " << evenCounter << "\toddCounter " << oddCounter << endl;
	}
	isEven = evenCounter > oddCounter;
	cout << "mostly even? " << isEven << endl;
	for (const auto& n : arr) {
		if (isEven && (n % 2 != 0)) {
			return n;
		} else if ((isEven == 0) && (n % 2 == 0)) {
			return n;
		}
	}
}

// https://www.codewars.com/kata/reviews/59f6032325db0562d3001224/groups/5a055444210a7bc6600001c1

int main() {
	std::vector<int> v = {2, 3, 4};
	cout << FindOutlier(v);
}