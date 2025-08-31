#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0, x; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			cin >> x;
			a[i][j] = x;
		}
	vector<vector<vector<int>>> f(n, vector<vector<int>>(2, vector<int>(2, 0x3f3f3f3f)));
	f[0][0][0] = 0;
	f[0][0][1] = 1;
	for(int i = 1; i < n; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				for(int l = 0; l < 2; ++l) {
					vector<int> x(m, -1), y = a[i - 1], z = a[i];
					if(i != 1)
						x = a[i - 2];
					if(j)
						for(int s = 0; s < m; ++s)
							x[s] = 1 - x[s];
					if(k)
						for(int s = 0; s < m; ++s)
							y[s] = 1 - y[s];
					if(l)
						for(int s = 0; s < m; ++s)
							z[s] = 1 - z[s];
					bool flag = true;
					for(int s = 0; flag && s < m; ++s)
						if(x[s] != y[s] && y[s] != z[s] && (!s || y[s] != y[s - 1]) && (s == m - 1 || y[s] != y[s + 1]))
							flag = false;
					if(flag && i == n - 1)
						for(int s = 0; flag && s < m; ++s)
							if(z[s] != y[s] && (!s || z[s] != z[s - 1]) && (s == m - 1 || z[s] != z[s + 1]))
								flag = false;
					if(flag)
						f[i][k][l] = min(f[i][k][l], f[i - 1][j][k] + l);
				}
	int ans = 0x3f3f3f3f;
	for(int j = 0; j < 2; ++j)
		for(int k = 0; k < 2; ++k)
			ans = min(ans, f[n - 1][j][k]);
	if(ans == 0x3f3f3f3f)
		ans = -1;
	cout << ans << endl;
	return 0;
}