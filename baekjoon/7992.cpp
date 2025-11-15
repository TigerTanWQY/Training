#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[19];
int f[(1<<16)+3];

istream& operator>>(istream& oin, pair<int, int>& A)
{ return oin >> A.first >> A.second; }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int V, n;
	cin >> V >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	memset(f, 0x3f, sizeof f);
	const int m = 1<<n;
	for(int i = 0; i < m; ++i) {
		int tot = 0, mx = 0;
		for(int j = 0; j < n; ++j)
			if(i>>j & 1) {
				mx = max(mx, a[j].first);
				tot += a[j].second;
			}
		if(tot <= V)
			f[i] = mx;
	}
	for(int i = 1; i <= m; ++i)
		if(f[i] == 0x3f3f3f3f) {
			int mn = 0x3f3f3f3f;
			for(int j = i; j; j = (j-1) & i)
				if(j != i)
					mn = min(mn, f[j] + f[j ^ i]);
			f[i] = mn;
		}
	cout << f[m-1] << endl;
	return 0;
}
