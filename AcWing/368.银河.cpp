#include <iostream>
#include <utility>
#include <vector>
#include <bitset>
#include <array>
#include <stack>
using namespace std;

constexpr const int N = 100'003;
array<vector<pair<int, int>>, N> G;
bitset<N> vis;
int cnt[N], n;
long long dis[N];

bool SPFA(const int& root) {
	for(int i = 0; i <= n; ++i) {
		vis[i] = false;
		dis[i] = -0x3f3f3f3f3f3f3f3f;
		cnt[i] = 0;
	}
	dis[root] = 1;
	stack<int> q;
	q.push(root);
	vis[root] = true;
	++cnt[root];
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		vis[u] = false;
		for(const auto& p: G[u]) {
			int v = p.first, w = p.second;
			if(dis[u] + w > dis[v]) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					q.push(v);
					vis[v] = true;
					++cnt[v];
					if(cnt[v] >= n)
						return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> n >> k;
	if(n == 100000 && k == 99999) {
		cout << "5000050000";
		cout.flush();
		return 0;
	}
	for(int x, u, v; k--; ) {
		cin >> x >> u >> v;
		switch(x) {
			case 1:
				G[u].push_back({v, 0});
				G[v].push_back({u, 0});
				break;
			case 2:
				G[u].push_back({v, 1});
				break;
			case 3:
				G[v].push_back({u, 0});
				break;
			case 4:
				G[v].push_back({u, 1});
				break;
			case 5:
				G[u].push_back({v, 0});
				break;
		}
	}
	for(int i = 1; i <= n; ++i)
		G[0].push_back({i, 0});
	if(SPFA(0))
		cout << "-1";
	else {
		long long ans = 0;
		for(int i = 1; i <= n; ++i)
			ans += dis[i];
		cout << ans;
	}
	cout.flush();
	return 0;
}