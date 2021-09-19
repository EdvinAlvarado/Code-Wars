#include <vector>
#include <string>
#include <map>

class StockList {
	public:
		static std::string stockSummary(std::vector<std::string> &listOfArt, std::vector<std::string> &categories) {
			if (listOfArt.empty() || categories.empty()) {return "";}

			std::map<char, int> cat_val;
			for (auto item: listOfArt) {cat_val[item[0]] += std::stoi(item.substr(item.find(" "), std::string::npos));}

			std::string results = "";
			for (auto it = categories.begin(); it != categories.end(); it++) {
				results += "(" + *it + " : " + std::to_string(cat_val[it->at(0)]) + ")";
				if (it+1 != categories.end()) {results += " - ";}
			}
			return results;
		};
};
