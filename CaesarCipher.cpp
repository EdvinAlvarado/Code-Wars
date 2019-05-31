#include <string>
#include <vector>
#include <iostream>
#include <cmath> // ceil
// #include <cctype> // isalpha


// not finished
class CaesarCipher
{
public:	
	static std::vector<std::string> movingShift(const std::string &s, int shift) {
		
		std::vector<std::string> strvec;

		std::string shift_str;
		for (const char& c: s) {
			
			if ((c >= 'a') && (c <= 'z')) {
				shift_str += 'a' + (c - 'a' + shift) % 26;
				shift  = (shift + 1) % 26;
			} else if ((c >= 'A') && (c <= 'Z')) {
				shift_str += 'A' + (c - 'A' + shift) % 26;
				shift  = (shift + 1) % 26;
			} else {
				shift_str += c;
			}
			
		}

		// std::cout << shift_str << std::endl;

		size_t strsize = shift_str.length();
		const size_t packSize = std::ceil((float)strsize / 5);
		int i = strsize;

		while (i != 0) {
			if (packSize <= i) {
				strvec.push_back(shift_str.substr(strsize - i, packSize));
				i -= packSize;
			} else {
				strvec.push_back(shift_str.substr(strsize-i, i));
				i == 0;
			}	
		}

		for (std::string& s: strvec) {
		std::cout << s << " ";
		}
		std::cout << std::endl;

		while (strvec.size() != 5) {
			strvec.push_back("");
		}
		return strvec;
	}
    static std::string demovingShift(std::vector<std::string> &s, int shift) {

		return "";
	}
};

int main() {
	auto strvec =  CaesarCipher::movingShift("I should", 1);
	for (std::string& s: strvec) {
		std::cout << s << " ";
	}
	std::cout << std::endl;
}