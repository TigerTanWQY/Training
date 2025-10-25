#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
int v[N], w[N], f[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, V;
	cin >> n >> V;
	for(int i = 1; i <= n; ++i)
		cin >> v[i] >> w[i];
	for(int i = n; i; --i)
		for(int j = 0; j <= V; ++j) {
			f[i][j] = f[i+1][j];
			if(j >= v[i])
				f[i][j] = max(f[i][j], f[i+1][j-v[i]] + w[i]);
		}
	for(int i = 1, j = V; i <= n; ++i)
		if(j >= v[i] && f[i][j] == f[i+1][j-v[i]] + w[i]) {
			cout << i << ' ';
			j -= v[i];
		}
	cout << endl; return 0;
}
