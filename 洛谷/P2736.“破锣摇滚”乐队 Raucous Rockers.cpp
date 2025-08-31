#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 20 + 1;
int f[N][N], a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V, m;
	cin >> n >> V >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		for(int k = m; k; --k)
			for(int j = V; j >= a[i]; --j)
				f[k][j] = max({f[k][j], f[k - 1][V] + 1, f[k][j - a[i]] + 1});
	cout << f[m][V];
	cout.flush();
	return 0;
}