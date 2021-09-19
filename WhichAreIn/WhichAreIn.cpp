// https://www.codewars.com/kata/which-are-in/train/cpp
 
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class WhichAreIn
{
	public:
	static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2) {
		std::vector<std::string> found;

		for (std::string ar2: array2) {
			for (std::string ar1: array1) {
				if ((ar2.find(ar1) != std::string::npos)) {
					found.push_back(ar1);
				}
			}
		}

		std::sort(found.begin(), found.end());
		found.erase(unique(found.begin(), found.end()), found.end());
		return found;
	}
};


int main() {
	std::vector<std::string> arr1 = { "arp", "live", "strong" };
	std::vector<std::string> arr2 = { "lively", "alive", "harp", "sharp", "armstrong" };
	for (std::string result: WhichAreIn::inArray(arr1, arr2)) {
		std::cout << result << std::endl;
	}
}