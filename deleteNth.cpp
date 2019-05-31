#include <vector>
#include <iostream>
#include <map>
using namespace std;

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
	std::map<int, int> counter;
	std::vector<int> v;
	for (const int& i: arr) {
		// if (counter.find(i) == counter.end()) { // not in map
		// 	counter[i] = 1;
		// 	v.push_back(i);
		// } 
		if (counter[i]++ < n) {
			v.push_back(i);

		}
	}
	return v;
}

int main()
{
	auto vec = deleteNth({20,37,20,21}, 1);
	for (const auto& n: vec) {
		cout << n << " ";
	}
	cout << endl;
}