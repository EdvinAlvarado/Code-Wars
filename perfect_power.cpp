#include <iostream>
#include <cmath>

using namespace std;

struct P {
	int base;
	int power;
};

P isPP(int n) {
	for (int m = 2; m <= int(ceil(sqrt(n))); ++m) {
		cout << m << endl;
		for (int k = 2;k <= int(ceil(log2(n))); ++k) {
			cout << k << " ";
			if (pow(m, k) == n) {
				return {m, k};
			}
		}
		cout << endl;		
	}
	return {0, 0};
}

int main() {
	auto fPP = isPP(81);
	int powerlist [2] = {fPP.base, fPP.power};

	cout << "\n\n[" << powerlist[0] << ", " << powerlist[1] << "]" << endl;
}