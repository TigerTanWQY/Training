#include<bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
int f[N][N][3], a[N], b[N], c[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i < n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < i; ++j)
			for(int k = 0; k < 3; ++k) {
				int add = 0, tt = -2e9;
				if((c[i] + 1) % 3 == k)
					add = (a[i] << 1);
				if(c[i] == k)
					add = a[i];
				if(j < i - 1 || i == 1)
					tt = max(tt, f[i - 1][j][k]);
				if(j > 0)
					tt = max(tt, max(f[i - 1][j - 1][(k + 1) % 3], f[i - 1][j - 1][(k + 2) % 3]) - b[j]);
				f[i][j][k] = tt + add;
			}
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans = max({ans, f[n][i][0], f[n][i][1], f[n][i][2]});
	cout << ans << endl;
	return 0;
}
