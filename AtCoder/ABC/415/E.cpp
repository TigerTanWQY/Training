#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	vector<LL> p(n + m - 1);
	for(int i = 0; i < n + m - 1; ++i)
		cin >> p[i];
	vector<vector<LL>> f(n, vector<LL>(m, 0));
	f[n-1][m-1] = (LL)p[n + m - 2] - (LL)a[n-1][m-1];
	for(int i = n - 1; i >= 0; --i)
		for(int j = m - 1; j >= 0; --j) {
			if(i == n - 1 && j == m - 1)
				continue;
			int k = i + j;
			LL res = 1e18;
			if(i + 1 < n)
				res = min(res, f[i+1][j]);
			if(j + 1 < m)
				res = min(res, f[i][j+1]);
			f[i][j] = max((LL)p[k] - (LL)a[i][j], res - ((LL)a[i][j] - (LL)p[k]));
		}
	cout << max(f[0][0], 0LL) << endl;
	return 0;
}
