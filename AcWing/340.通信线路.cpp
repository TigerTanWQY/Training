#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <bitset>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 1'001'003;
vector<pair<int, int>> G[N];
bitset<N> vis;
LL dis[N];

int read() {
	int res = 0;
	char ch = cin.get();
	for(; '0' > ch || ch > '9'; ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	return res;
}

void Dijkstra(const int x) {
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
	q.push({dis[1], 1});
	vis.reset();
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: G[u])
			if(w < x && dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = read(), m = read(), k = read();
	for(int u, v, w; m--; ) {
		u = read(); v = read(); w = read();
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		for(int i = 1; i <= k; ++i) {
			G[u + n * i].push_back({v + n * i, w});
			G[v + n * i].push_back({u + n * i, w});
			G[u + n * (i - 1)].push_back({v + n * i, 0});
			G[v + n * (i - 1)].push_back({u + n * i, 0});
		}
	}
	int L = 0, R = 1e9 + 1;
	while(L + 1 < R) {
		int M = (L + R) / 2;
		Dijkstra(M);
		LL res = 0x3f3f3f3f3f3f3f3f;
		for(int i = 0; i <= k; ++i)
			res = min(res, dis[n + n * i]);
		if(res == 0x3f3f3f3f3f3f3f3f)
			L = M;
		else
			R = M;
	}
	if(L == 1e9)
		L = -1;
	cout << L;
	cout.flush();
	return 0;
}