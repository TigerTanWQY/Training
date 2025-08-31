#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL f0 = 0, f1 = 1;
	for(char ch = cin.get(); ch == '0' || ch == '1'; ch = cin.get()) {
		f0 = f0 * 3 % P;
		if(ch == '1') {
			f0 = (f0 + f1) % P;
			f1 = f1 * 2 % P;
		}
	}
	cout << (f0 + f1) % P << endl;
	return 0;
}
