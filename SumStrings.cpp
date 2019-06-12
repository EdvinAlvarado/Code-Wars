// https://www.codewars.com/kata/5324945e2ece5e1f32000370/train/cpp
// Sum Strings as Numbers
//// Only numbers 0-9
#include <string>
#include <vector>
#include <cmath> // pow
#include <iostream>
#include <numeric> // accumulate

int str_to_int(std:: string s) {
	std::vector<int> v;
	int counter = s.length() - 1;
	for (char& c: s) {
		v.push_back((c - '0') * pow(10, counter--));
	}
	return std::accumulate(v.begin(), v.end(), 0);
}

std::string sum_strings(std::string a, std::string b) {
	// std::cout << pow(2,2) << std::endl;
	return "";
}

int main() {
	std::string test = sum_strings("2", "3");
}