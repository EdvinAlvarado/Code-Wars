#include <iostream>
#include <string>
#include <regex>

const std::regex morse("([^\\s]+|\\s{3})");

std::string decodeMorse(std::string morseCode) {
  std::string decoded;
  
  auto begin = morseCode.begin() + morseCode.find_first_not_of(' ');
  auto end = morseCode.begin() + morseCode.find_last_not_of(' ') + 1;
  
  for (auto it = std::sregex_iterator(begin, end, morse); it != std::sregex_iterator(); ++it) {
    std::string str = it->str();
    decoded += (str == "   " ? " " : MORSE_CODE[str]);
  }
  
  return decoded;
}


int main() {
	std::cout << decodeMorse(".... . -.--   .--- ..- -.. .") << std::endl;
}