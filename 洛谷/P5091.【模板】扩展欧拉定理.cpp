#include <iostream>
using namespace std;

int p;

int qpow(int a, int b) {
	int res = 1;
	for(; b; a = (long long)a * a % p, b >>= 1)
		if(b & 1)
			res = (long long)res * a % p;
	return res;
}

int phi(int x) {
	int res = 1;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0) {
			res *= i - 1;
			x /= i;
			for(; x % i == 0; x /= i)
				res *= i;
		}
	if(x > 1)
		res *= x - 1;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	cin >> a >> p;
	a %= p; const int m = phi(p);
	char ch = cin.get();
	for(; '0' > ch || ch > '9'; ch = cin.get());
	bool flag = false;
	int b = 0;
	for(; b = b * 10 + ch - '0', ch = cin.get(), '0' <= ch && ch <= '9'; )
		if(b >= m)
		{ flag = true; b %= m; }
	if(b >= m)
	{ flag = true; b %= m; }
	if(flag)
		b += m;
	cout << qpow(a, b) << endl;
	return 0;
}
