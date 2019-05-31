#include <vector>
#include <map>
#include <iostream>

int score(const std::vector<int>& dice) {
	std::map<int,int> dvalue_counter;
	int result = 0;
	for (const int& dvalue: dice) {
		std::cout << dvalue << " ";
		dvalue_counter[dvalue]++;
	}
	for (auto it = dvalue_counter.begin(); it != dvalue_counter.end(); it++) {
		// std::cout << it->first << "\t" << it->second << std::endl;
		if (it->second == 3) {
			if (it->first == 1) {
				result += 1000;
				dvalue_counter[it->first] -= 3;
			} else if (it->first == 6) {
				result += 600;
				// dvalue_counter[it->first] -= 3;
			} else if (it->first == 5) {
				result += 500;
				dvalue_counter[it->first] -= 3;
			} else if (it->first == 4) {
				result += 400;
				// dvalue_counter[it->first] -= 3;
			} else if (it->first == 3) {
				result += 300;
				// dvalue_counter[it->first] -= 3;
			} else if (it->first == 2) {
				result += 200;
				// dvalue_counter[it->first] -= 3;
			}
		}

		if (it->first == 1) {
			result += it->second * 100;
		} else if (it->first == 5) {
			result += it->second * 50;
		}
	}
	return result;
}

int main() {
	const std::vector<int> dice_throws = {3, 3, 3, 3, 3};
	std::cout << score(dice_throws) << std::endl; 
}