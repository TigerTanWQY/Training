#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
int f[N][12], fa[N];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	memset(f, -1, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[i][1] = fa[i] = i;
	for(int t, u, k; q--; ) {
		cin >> t >> u >> k;
		u = fnd(u);
		if(t == 1) {
			k = fnd(k);
			if(u == k)
				continue;
			vector<int> a;
			for(int i = 1; i <= 10; ++i)
				a.push_back(f[k][i]);
			for(int i = 1; i <= 10; ++i)
				a.push_back(f[u][i]);
			sort(a.rbegin(), a.rend());
			fa[k] = u;
			for(int i = 0; i < 10; ++i)
				f[u][i + 1] = a[i];
		} else
			cout << f[u][k] << '\n';
	}
	cout.flush();
	return 0;
}