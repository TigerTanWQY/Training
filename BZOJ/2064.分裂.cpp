#include <bits/stdc++.h>
using namespace std;

int s[(1<<20)+3], f[(1<<20)+3];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> s[1 << i];
	cin >> m;
	for(int i = 1, x = 1<<n; i <= m; ++i, x <<= 1) {
		cin >> s[x];
		s[x] = -s[x];
	}
	int T = (1 << n+m) - 1;
	for(int i = 1; i <= T; ++i) {
		s[i] = s[i & -i] + s[i ^ (i & -i)];
		for(int j = 0; j < n + m; ++j)
			if(i >> j & 1)
				f[i] = max(f[i], f[i - (1 << j)]);
		f[i] += !s[i];
	}
	cout << n + m - f[T] * 2 << endl;
	return 0;
}
