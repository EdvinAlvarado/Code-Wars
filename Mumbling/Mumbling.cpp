#include <string>
#include <iostream>
#include <cctype> //tolower toupper

class Accumul
{
public:
	static std::string accum(const std::string &s) {
		std::string accumtext; 
		for (int i = 0; i < s.size(); i++) {
			accumtext += char(std::toupper(s[i]));
			for (int j = 0; j < i; j++) {
				accumtext += char(std::tolower(s[i]));
			}
			if (i != s.size() - 1) {
				accumtext += "-";
			}
		}
		return accumtext;
	}
};

int main() {
	std::cout << Accumul::accum("ABCD") << std::endl;
}