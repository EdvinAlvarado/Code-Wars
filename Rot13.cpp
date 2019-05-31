#include <string>
#include <iostream>
using namespace std;

string rot13(string msg)
{
	string rotmsg = "";
	for (const char& c: msg ) {
		char rotc = c + 13;
		cout << c << "\t" << rotc << endl;
		if (isupper(c)) {
				if (isupper(rotc)) {
					rotmsg.push_back(rotc);
				} else {
					rotmsg.push_back(rotc - 26);
				}
		} else if (islower(c)) {
				if (islower(rotc)) {
					rotmsg.push_back(rotc);
				} else {
					rotmsg.push_back(rotc - 26);
				}
		} else {
			rotmsg.push_back(c);
		}
	}
	return rotmsg;
}


int main() {
	std::cout << rot13("Test+") << std::endl;
}