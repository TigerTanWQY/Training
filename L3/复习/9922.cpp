#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1003][1003], f[10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T, n, V;
	cin >> T >> n >> V;
	for(int i = 1; i <= T; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> a[j][i];
	for(int k = 1; k < T; ++k) {
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; ++i)
			for(int j = a[i][k]; j <= V; ++j)
				f[j] = max(f[j], f[j - a[i][k]] + a[i][k + 1] - a[i][k]);
		V += f[V];
	}
	cout << V << endl;
	return 0;
}