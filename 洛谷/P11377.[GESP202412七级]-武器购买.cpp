#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103;
int f[50003], v[N], w[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, V, W; _T--; cout.put('\n')) {
		cin >> n >> W >> V;
		for(int i = 1; i <= n; ++i)
			cin >> w[i] >> v[i];
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; ++i)
			for(int j = V; j >= v[i]; --j)
				f[j] = max(f[j], f[j - v[i]] + w[i]);
		if(f[V] < W) {
			cout << "-1";
			continue;
		}
		int ans = V;
		for(int i = 1; i <= V; ++i)
			if(f[i] >= W)
			{ ans = min(ans, i); break; }
		cout << ans;
	}
	cout.flush();
	return 0;
}
