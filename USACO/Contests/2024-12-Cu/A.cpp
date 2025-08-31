#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL f[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	f[1] = 0;
	for(int i = 2; i <= 11; ++i)
		f[i] = f[i - 1] * 10 + 5;
	for(int i = 2; i <= 11; ++i)
		f[i] += f[i - 1];
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		if(n < 10)
		{ cout.put('0'); continue; }
		int k = log10(n);
		LL x = 0;
		for(int _ = k + 1; _--; )
			x = x * 10 + 4;
		cout << f[k] + max(0LL, min((LL)n, 5 * (LL)pow(10, k) - 1) - x);
	}
	cout.flush();
	return 0;
}
