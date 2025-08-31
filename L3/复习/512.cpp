#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 103;
int v[N], w[N], t[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> v[i] >> w[i] >> t[i];
	for(int i = 1; i <= n; ++i)
		for(int j = m; j >= v[i]; --j)
			for(int l = k; l >= t[i]; --l)
				f[j][l] = max(f[j][l], f[j - v[i]][l - t[i]] + w[i]);
	cout << f[m][k] << endl;
	return 0;
}