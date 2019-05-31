#include <string>
#include <iostream>
#include <map>
using namespace std;

bool valid_braces(std::string braces) 
{
	std::map<char, int> bracketmap;

	for (int i = 0; i < braces.size(); i++) {
		size_t strsize = braces.size();
		bracketmap[braces[i]]++;
		cout << braces[i];
		if (braces[i] == '(') {
			if (!((i+1 == braces.find_first_of(')')) || (i+1 == strsize - braces.rfind(')')))) {
				return false;
			}
		} else if (braces[i] == '[') {
			if (!((i+1 == braces.find_first_of(']')) || (i+1 == strsize - braces.rfind(']')))) {
				return false;
			}			
		} else if (braces[i] == '{') {
			if (!((i+1 == braces.find_first_of('}')) || (i+1 == strsize - braces.rfind('}')))) {
				return false;
			}			
		}

	}
	cout << endl;

	if (bracketmap['('] + bracketmap[')'] % 2) {
		return false;
	} else if (bracketmap['['] + bracketmap[']'] % 2) {
		return false;
	} else if (bracketmap['{'] + bracketmap['}'] % 2) {
		return false;
	}
	return true;
}



int main()
{
	cout << valid_braces("()") << endl;
}