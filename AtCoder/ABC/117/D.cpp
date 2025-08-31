#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[100003], f[43];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; LL k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	LL tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += a[i];
	auto b = bitset<43>((unsigned long long)k << 1);
	LL ans = tot; int m = 0;
	f[1] = 1;
	for(int cnt; k; k >>= 1) {
		cnt = 0; ++m;
		f[m + 1] = f[m] << 1;
		for(int i = 1; i <= n; ++i)
			a[i] & 1? --cnt: ++cnt;
		for(int i = 1; i <= n; ++i)
			a[i] >>= 1;
		f[m] *= max(cnt, 0);
	}
	for(int i = 1; i <= m; ++i)
		f[i] += f[i - 1];
	for(int i = m; i; --i)
		if(b[i]) {
			ans = max(ans, tot + k + f[i - 1]);
			k += f[i] - f[i - 1];
		}
	ans = max(ans, tot + k);
	cout << ans << endl;
	return 0;
}
