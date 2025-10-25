#include <bits/stdc++.h>
using namespace std;

int a[103], f[25003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		cin >> n;
		m = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			m = max(m, a[i]);
		}
		sort(a + 1, a + n + 1);
		f[0] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = a[i]; j <= m; ++j)
				f[j] += f[j - a[i]];
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			ans += (f[a[i]] == 1);
		cout << ans;
		memset(f, 0, sizeof f);
	}
	cout.flush(); return 0;
}
