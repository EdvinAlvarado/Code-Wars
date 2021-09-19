#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <string>
#include <algorithm>
#include <map>
#include <iterator> // advance and next
// using namespace std;

class RomanNumerals 
{	
private:
	static std::string toRomanUnit(int magnitude, int val) {
		std::vector<std::tuple<char, char, char>> roman_symbols;
		roman_symbols.push_back(std::make_tuple('I', 'V', 'X'));
		roman_symbols.push_back(std::make_tuple('X', 'L', 'C'));
		roman_symbols.push_back(std::make_tuple('C', 'D', 'M'));
		roman_symbols.push_back(std::make_tuple('M', 'Z', 'Z'));

		std::string result;
		// char must be added per line if not they sum each other and then get added to results.
		if (val == 1) {
			result += std::get<0>(roman_symbols[magnitude]);
		} else if (val == 2) {
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
		} else if (val == 3) {
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
		} else if (val == 4) {
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<1>(roman_symbols[magnitude]);
		} else if (val == 5) {
			result += std::get<1>(roman_symbols[magnitude]);
		} else if (val == 6) {
			result += std::get<1>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
		} else if (val == 7) {
			result += std::get<1>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
		} else if (val == 8) {
			result += std::get<1>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<0>(roman_symbols[magnitude]);
		} else if (val == 9) {
			result += std::get<0>(roman_symbols[magnitude]);
			result += std::get<2>(roman_symbols[magnitude]);
		} else {
			result = "";
		}

		return result;
	}

public:
	static std::string to_roman(int n) {	

		std::vector<std::string> roman_vec;
		for (int i = 0; i < 4; ++i) {
			roman_vec.push_back(toRomanUnit(i, n % 10));
			// std::cout << i << " " << n % 10 << std::endl;
			n /= 10;
		}

		// std::cout << std::endl;
		std::string roman_num;
		for (auto it = roman_vec.rbegin(); it != roman_vec.rend(); ++it) {
			// std::cout << *it;
			roman_num += *it;
		}
		
		return roman_num;
	};

	static int from_roman(std::string roman_n) {

		int n = 0;

		std::vector<std::tuple<char, char, char>> roman_symbols;
		roman_symbols.push_back(std::make_tuple('I', 'V', 'X'));
		roman_symbols.push_back(std::make_tuple('X', 'L', 'C'));
		roman_symbols.push_back(std::make_tuple('C', 'D', 'M'));
		roman_symbols.push_back(std::make_tuple('M', 'Z', 'Z'));

		std::map<char, int> rmap;
		rmap['I'] = 1;
		rmap['V'] = 5;
		rmap['X'] = 10;
		rmap['L'] = 50;
		rmap['C'] = 100;
		rmap['D'] = 500;
		rmap['M'] = 1000;
		rmap['Z'] = 9999;

		for (auto c_it = roman_n.begin(); c_it != roman_n.end(); ++c_it) {

			// std::cout << *c_it << std::endl;

			// Chechk if last
			if (c_it == roman_n.end() - 1) {
				n += rmap.find(*c_it)->second;
				return n;
				break;
			}

			auto next_c_it = std::next(c_it);			
			auto next_mid_it = std::find_if(roman_symbols.begin(), roman_symbols.end(), [&](const std::tuple<char,char,char>& e) {return std::get<1>(e) == *next_c_it;});
			auto next_tier_it = std::find_if(roman_symbols.begin(), roman_symbols.end(), [&](const std::tuple<char,char,char>& e) {return std::get<0>(e) == *next_c_it;});

			// Gives you which vector iterator the *c_it is located. Mid looks in the middle column and the other in the first column.
			auto mid_it = std::find_if(roman_symbols.begin(), roman_symbols.end(), [&](const std::tuple<char,char,char>& e) {return std::get<1>(e) == *c_it;});
			auto tier_it = std::find_if(roman_symbols.begin(), roman_symbols.end(), [&](const std::tuple<char,char,char>& e) {return std::get<0>(e) == *c_it;});

			// middle symbol
			if (mid_it != roman_symbols.end()) { //5,6,7,8
				// Are they in the same vector therfore being of the same magnitude.
				if (mid_it == next_tier_it) { //6,7,8

					auto next_next_c_it = std::next(c_it, 2);
					auto next_next_next_c_it = std::next(c_it, 3);
					// next_c_it will always be smaller.
					if (rmap.find(*next_c_it)->second == rmap.find(*next_next_next_c_it)->second) { //8

						n += rmap.find(*c_it)->second;
						n += 3*rmap.find(*next_c_it)->second;
						std::advance(c_it, 3);

					} else if (rmap.find(*next_c_it)->second == rmap.find(*next_next_c_it)->second) { //7

						n += rmap.find(*c_it)->second;
						n += 2*rmap.find(*next_c_it)->second;
						std::advance(c_it, 2);

					} else { //6

						n += rmap.find(*c_it)->second;
						n += rmap.find(*next_c_it)->second;
						std::advance(c_it, 1);
					}					
				} else { //5
					n += rmap.find(*c_it)->second;
				}

			} else { //1,2,3,4,9,stop
				
				if (rmap.find(*c_it)->second == rmap.find(*next_c_it)->second) { //2,3	

					auto next_next_c_it = std::next(c_it, 2);
					if (rmap.find(*c_it)->second == rmap.find(*next_next_c_it)->second) { // 3

						n += 3*rmap.find(*c_it)->second;
						std::advance(c_it, 2);

					} else { // 2

						n += 2*rmap.find(*c_it)->second;
						std::advance(c_it, 1);
					}

				} else if (rmap.find(*c_it)->second < rmap.find(*next_c_it)->second) { //4,9
					
					if (next_mid_it != roman_symbols.end()) { //next_c_it is middle symbol ;4

						n += 4*rmap.find(*c_it)->second;
						std::advance(c_it, 1);

					} else { // next_c_it not middle symbol; 9

						n += 9*rmap.find(*c_it)->second;
						std::advance(c_it, 1);
					}

				} else if (rmap.find(*c_it)->second > rmap.find(*next_c_it)->second) { //1,stop

					n += rmap.find(*c_it)->second;
				}
			}
		} 

		return n;
	}
};


int main() {
	// std::string val = RomanNumerals::to_roman(11);
	// std::cout << "\n" << val << std::endl;
	for (int i = 1; i <= 2001; ++i) {
		std::string roman = RomanNumerals::to_roman(i);
		std::cout << i << std::endl;
		std::cout << "to_roman " << roman << std::endl;

		int n = RomanNumerals::from_roman(roman);	
		std::cout << "from_roman " << n << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
}