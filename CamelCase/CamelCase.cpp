//https://www.codewars.com/kata/convert-string-to-camel-case/train/cpp
#include <string>
#include <regex>
#include <iostream>

std::string to_camel_case(std::string text) {
	const std::regex camelregex("[A-Za-z]+");
	bool first_switch = 0;
	std::string cameltext = "";
	// std::cout << text << "\n" << "--------------" << std::endl;
	for (auto it = std::sregex_iterator(text.begin(), text.end(), camelregex); it != std::sregex_iterator(); ++it) {
		// std::cout << it->str() << std::endl;
		if (first_switch) {
			// toupper gives the ascci code instead of char type.
			cameltext += char(std::toupper(it->str()[0])) + it->str().substr(1, it->str().size());
		} else {
			first_switch = 1;
			cameltext += it->str();
		}
	}
	return cameltext;
}

int main() {
	std::cout << to_camel_case("the_stealth_warrior") << std::endl;
}