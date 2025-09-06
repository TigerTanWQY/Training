#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
int A[N], B[N], d[N], t[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> A[i] >> B[i];
		++d[A[i]]; ++d[B[i]];
	}
	for(; m; m--) {
		int u = A[m], v = B[m];
		if(d[u] > d[v])
			swap(u, v);
		else if(d[u] == d[v] && u > v)
			swap(u, v);
		G[u].push_back(v);
	}
	int ans = 0;
	for(int u = 1; u <= n; ++u) {
		for(const auto& v: G[u])
			t[v] = u;
		for(const auto& v: G[u])
			for(const auto& w: G[v])
				if(t[w] == u)
					++ans;
	}
	cout << ans << endl;
	return 0;
}
