#include <string>

// My solution
std::string ip(uint32_t n) {
	std::string r = "";
	for (int i = 0; i < 4; i++) {
		r += std::to_string((n %= 1UL << (8*(4-i))) >> 8*(3-i));
		if (i < 3) {r+=".";}
	}
	return r;
}

// My Favorite solution
#include <sstream>

std::string uint32_to_ip(uint32_t ip) {
	std::stringstream r{};
	r << (ip >> 24) << '.' << (ip >> 16 & 0xFF) << '.' << (ip >> 8 & 0xFF) << '.' << (ip & 0xFF);
	return r.str();
}
