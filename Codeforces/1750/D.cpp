#include <bits/stdc++.h>
using namespace std;

int a[200003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
		bool flg = true;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(i > 1 && a[i - 1] % a[i] != 0)
				flg = false;
		}
		if(!flg) {
			cout.put('0');
			continue;
		}
		long long ans = 1;
		for(int i = 2; i <= n; ++i) {
			int d = a[i - 1] / a[i], x = m / a[i], y = 0;
			vector<int> c;
			for(int j = 2; j * j <= d; ++j)
				if(d % j == 0) {
					int len = c.size();
					for(int k = 0; k < len; ++k)
						c.push_back(-c[k] * j);
					c.push_back(j);
					for(; d % j == 0; d /= j);
				}
			if(d > 1) {
				int len = c.size();
				for(int j = 0; j < len; ++j)
					c.push_back(-c[j] * d);
				c.push_back(d);
			}
			for(const auto& j: c)
				y += x / j;
			ans = ans * (x - y) % 998244353;
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
