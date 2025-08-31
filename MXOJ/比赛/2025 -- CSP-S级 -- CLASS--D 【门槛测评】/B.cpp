#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
vector<int> G[N], T[N];
int dep[N], pa[N];

int main() {
	freopen("eat.in", "r", stdin);
	freopen("eat.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(dep, -1, sizeof(dep));
	dep[1] = 0;
	memset(pa, -1, sizeof(pa));
	queue<int> q;
	q.push(1);
	vector<int> od;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		od.push_back(u);
		for(const auto& v: G[u]) {
			if(v == pa[u])
				continue;
			pa[v] = u;
			dep[v] = dep[u] + 1;
			T[u].push_back(v);
			q.push(v);
		}
	}
	reverse(begin(od), end(od));
	vector<int> div;
	for(int i = 1; i * i <= n; ++i)
		if(n % i == 0) {
			div.push_back(i);
			if(i != n / i)
				div.push_back(n / i);
		}
	int ans = 0;
	for(const auto& k: div) {
		vector<int> f(n + 1, 0);
		bool flg = true;
		for(const auto& u: od) {
			f[u] = 1;
			for(const auto& v: T[u])
				f[u] += f[v];
			if(f[u] > k) {
				flg = false;
				break;
			} else if(f[u] == k)
				f[u] = 0;
		}
		if(flg && f[1] == 0)
			++ans;
	}
	cout << ans << endl;
	return 0;
}
