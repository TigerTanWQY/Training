#include <iostream>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7;

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	LL b;
	cin >> a >> b;
	cout << qpow(a, b);
	cout.flush();
	return 0;
}