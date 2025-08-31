#include <bits/stdc++.h>
using namespace std;

int f[503][503];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1, L, R; i <= m; ++i) {
		cin >> L >> R;
		++f[L][R];
	}
	for(int i = n; i; --i)
		for(int j = i; j <= n; ++j)
			f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
	for(int L, R; q--; cout.put('\n')) {
		cin >> L >> R;
		cout << f[L][R];
	}
	cout.flush();
	return 0;
}
