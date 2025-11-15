#include <bits/stdc++.h>
using namespace std;

int a[19], b[19], ca[(1<<16)+3], cb[(1<<16)+3], f[(1<<16)+3][125];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	const int m = 1<<n;
	int tota = 0, totb = 0;
	for(int i = 0; i < n; ++i) {
		char ch;
		cin >> ch >> a[i] >> b[i];
		tota += a[i]; totb += b[i];
		for(int j = 0; j < m; ++j)
			if(j>>i & 1)
				if(ch == 'R')
					++ca[j];
				else
					++cb[j];
	}
	memset(f, -1, sizeof f);
	f[0][0] = 0;
	for(int S = 0; S < m; ++S)
		for(int j = 0; j <= 122; ++j)
			if(~f[S][j])
				for(int i = 0; i < n; ++i) {
					if(S>>i & 1)
						continue;
					int T = S | 1<<i,
						ma = min(a[i], ca[S]), mb = min(b[i], cb[S]);
					f[T][j+ma] = max(f[T][j+ma], f[S][j] + mb);
				}
	int ans = 1e9;
	for(int i = 0; i <= 122; ++i)
		if(~f[m-1][i])
			ans = min(ans, max(tota - i, totb - f[m-1][i]));
	cout << ans+n << endl;
	return 0;
}
