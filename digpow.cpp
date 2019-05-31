//https://www.codewars.com/kata/5552101f47fc5178b1000050/train/cpp
//PLaying with digits

#include <iostream>
#include <algorithm>
// #include <vector>
#include <cmath>

class DigPow
{
public:
	static int digPow(int n, int p) {
		
		// std::vector<int> v;
		// int vnum = n; 
		// while (vnum != 0) {
		// 	v.push_back(vnum % 10);
		// 	vnum /= 10;
		// }
		// reverse(v.begin(), v.end());
		
		unsigned int m = 0;
		// for (int i = 0; i < v.size(); i++) {
		// 	m += pow(v[i], p+i);
		// }
		for (char digit: std::to_string(n)) {
			m += pow(digit-'0',p++);
		}

		// if (m % n == 0) {
		// 	return m/n;
		// } else {
		// 	return -1;
		// }
		return m%n == 0 ? m/n : -1;

  }
};

int main() {
	std::cout << DigPow::digPow(46288, 3) << std::endl;
}
