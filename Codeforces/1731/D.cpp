#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
int n, m;

bool chk(int len) {
	vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			c[i][j] = c[i][j - 1] + c[i - 1][j] - c[i - 1][j - 1] + (a[i][j] >= len);
	for(int sx = 1; sx + len - 1 <= n; ++sx)
		for(int sy = 1; sy + len - 1 <= m; ++sy) {
			int ex = sx + len - 1, ey = sy + len - 1;
			if(c[ex][ey] - c[ex][sy - 1] - c[sx - 1][ey] + c[sx - 1][sy - 1] == len * len)
				return true;
		}
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(; _T--; cout.put('\n')) {
		cin >> n >> m;
		a.assign(n + 1, vector<int>(m + 1));
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> a[i][j];
		int L = 1, R = min(n, m);
		while(L <= R) {
			int M = (L + R) >> 1;
			if(chk(M))
				L = M + 1;
			else
				R = M - 1;
//			cout << L << ' ' << R << '\n';
		}
		cout << L - 1;
	}
	cout.flush(); return 0;
}
