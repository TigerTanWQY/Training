#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
unordered_map<int, bool> b;
int a[N], c[N], cnt = 0;

int main() {
	a[1] = 1;
	for(int i = 2; i <= 1e5; ++i) {
		if(!b[i]) {
			c[++cnt] = i;
			a[i] = a[i - 1];
		}
		for(int j = 1; j <= cnt; ++j) {
			if(c[j] * i > 1e6)
				break;
			b[c[j] * i] = true;
			a[c[j] * i] = a[c[j]] + a[i];
			if(!(i % c[j]))
				break;
		}
	}
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		long long ans = 1;
		cin >> n;
		for(int i = 1, p, q; i <= n; ++i) {
			cin >> p >> q;
			if(p == 2)
				--ans;
			ans += (long long)a[p] * q;
		}
		cout << ans;
	}
	cout.flush();
	return 0;
}
