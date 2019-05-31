#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class DoubleLinear
{
public:
    static int dblLinear(int n) {

		std::vector<int> bVec = {1};
		std::vector<int> tVec;

		for (int x = 0; x < ceil(log2(n)); x++) {

			for (auto it = bVec.end() - pow(2,x); it != bVec.end(); it++) {
			tVec.push_back(2* *it + 1);
			tVec.push_back(3* *it + 1);
			}

			bVec.insert(bVec.end(), tVec.begin(), tVec.end());
			tVec.clear();			
		}
		std::sort(bVec.begin(), bVec.end());
		bVec.erase(std::unique(bVec.begin(), bVec.end()), bVec.end());		

		for (auto it = bVec.begin(); it != bVec.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		
		return bVec[n];
	}
};

int main() {
	std::cout << DoubleLinear::dblLinear(50) << std::endl;
}