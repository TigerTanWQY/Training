#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
int dis1[N], dis2[N], f1[N], f2[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	string s;
	cin >> s;
	memset(dis1, 0x3f, sizeof dis1);
	memset(dis2, 0x3f, sizeof dis2);
	memset(f1, -1, sizeof f1);
	memset(f2, -1, sizeof f2);
	queue<tuple<int, int, int>> q;
	for(int i = 1; i <= n; ++i)
		if(s[i-1] == 'S') {
			dis1[i] = 0;
			f1[i] = i;
			q.push({0, i, i});
		}
	while(!q.empty()) {
		auto [dis, fa, u] = q.front();
		q.pop();
		if(dis > dis2[u])
			continue;
		for(const auto& v: G[u]) {
			int tdis = dis + 1;
			if(tdis < dis1[v]) {
				if(f1[v] != fa) {
					dis2[v] = dis1[v];
					f2[v] = f1[v];
				}
				dis1[v] = tdis;
				f1[v] = fa;
				q.push({tdis, fa, v});
			} else if(tdis < dis2[v] && fa != f1[v]) {
				dis2[v] = tdis;
				f2[v] = fa;
				q.push({tdis, fa, v});
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		if(s[i-1] == 'D')
			cout << dis1[i] + dis2[i] << '\n';
	cout.flush(); return 0;
}
