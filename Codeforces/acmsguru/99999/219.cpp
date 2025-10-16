#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
vector<pair<int, int>> G[N];
bool res[N];
int in[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		--u; --v;
		G[u].push_back({v, w});
		if(w == 0)
			++in[v];
	}
	queue<int> q;
	for(int i = 0; i < n; ++i)
		if(!in[i]) {
			q.push(i);
			res[i] = true;
		}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(const auto& [v, w]: G[u])
			if(!w && !--in[v]) {
				q.push(v);
				res[v] = true;
			}
	}
	for(int i = 0; i < n; ++i)
		if(!res[i])
			q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(const auto& [v, _]: G[u])
			if(res[v]) {
				q.push(v);
				res[v] = false;
			}
	}
	for(int i = 0; i < n; ++i)
		cout << res[i] << '\n';
	cout.flush(); return 0;
}
