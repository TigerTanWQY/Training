#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a *= a, b >>= 1)
		if(b & 1)
			res *= a;
	return res;
}

LL f(LL x) {
	vector<int> a;
	for(; x; x /= 10)
		a.push_back(x % 10);
	reverse(begin(a), end(a));
	const int n = a.size();
	LL res = 0;
	for(int i = 1; i <= n; ++i) {
		if(i == n) {
			++res;
			break;
		}
		res += qpow(a[0], n - i - 1) * min(a[0], a[i]);
		if(a[i] >= a[0])
			break;
	}
	for(int i = 0; i < n; ++i)
		for(int j = 1; j < (i? 10: a[0]); ++j)
			res += qpow(j, n - i - 1);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL L, R;
	cin >> L >> R;
	cout << f(R) - f(L - 1) << endl;
	return 0;
}
