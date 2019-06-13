// https://www.codewars.com/kata/5324945e2ece5e1f32000370/train/cpp
// Sum Strings as Numbers
//// Only numbers 0-9
#include <string>
#include <vector>
#include <cmath> // pow
#include <iostream>
#include <numeric> // accumulate
#include <algorithm> // max, transform, copy
#include <functional> // plus
#include <iterator> // bakc_inserter

std::vector <short int> str_to_vint(std:: string s) {
	std::vector<short int> v;
	for (char& c: s) {
		v.push_back(c - '0');
	}
	return v;
}

void print_vector(std::vector <short int> v) {
	std::cout << "{";
	for (short int& n: v) {
		std::cout << n << ", ";
	}
	std::cout << "}" << std::endl;
}

std::string sum_strings(std::string a, std::string b) {
	
	auto v1 = str_to_vint(a);
	auto v2 = str_to_vint(b);

	auto max_size = std::max(v1.size(), v2.size());
	auto min_size = std::min(v1.size(), v2.size());
	auto dif_size = max_size - min_size;
	std::vector<short int> v(max_size);

	if (max_size == min_size) {
		std::transform(v1.begin(), v1.end(), v2.begin(), v.begin(), std::plus<int>());
	} else if (v1.size() == max_size) {
		// std::copy(v1.begin(), v1.begin()+dif_size, std::back_inserter(v));
		v.assign(v1.begin(), v1.begin()+dif_size);
		v.resize(max_size);
		std::transform(v1.begin() + dif_size, v1.end(), v2.begin(), v.begin()+ dif_size, std::plus<int>());
	} else if (v2.size() == max_size) {
		v.assign(v2.begin(), v2.begin()+dif_size);
		v.resize(max_size);
		std::transform(v2.begin() + dif_size, v2.end(), v1.begin(), v.begin()+ dif_size, std::plus<int>());
	}

	std::vector<short int> finalv;
	for (auto it = v.rbegin(); it != v.rend(); ++it) {
		// std::cout << *it << " ";
		if (*it > 9) {
			if (it  == v.rend()-1) {
				finalv.push_back(*it - 10);
				finalv.push_back(1);
			} else{
				finalv.push_back(*it - 10);
				*(it+1) += 1;
			}			
		} else {
			finalv.push_back(*it);
		}
	}
	// std::cout << std::endl;

	std::reverse(finalv.begin(), finalv.end());

	if (finalv[0] == 0 && finalv.size() > 1) {
		finalv.erase(finalv.begin());
	}

	print_vector(v1);
	print_vector(v2);
	print_vector(v);
	print_vector(finalv);

	std::string str = "";
	for (short int& n: finalv) {
		str.append(std::to_string(n));
	}
	return str;	
}

int main() {
	std::string test = sum_strings("99", "2");
	std::cout << test << std::endl;
}