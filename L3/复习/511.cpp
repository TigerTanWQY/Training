#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 1000, C = N + 3;
vector<int> c[C];
int a[C], v[C], w[C], f[C][C];

int main() {
	ios::sync_with_stdio(false);
	int n, V;
	cin >> n >> V;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> v[i] >> w[i];
		c[a[i]].push_back(i);
	}
	for(int i = 1; i <= N; ++i)
		for(int j = 0; j <= V; ++j) {
			f[i][j] = f[i - 1][j];
			for(const auto &k: c[i])
				if(j >= v[k])
					f[i][j] = max(f[i][j], f[i - 1][j - v[k]] + w[k]);
		}
	cout << f[N][V] << endl;
	return 0;
}