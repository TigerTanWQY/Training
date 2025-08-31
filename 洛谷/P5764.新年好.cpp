#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 5e4 + 3;
vector<pair<int, int>> G[N];
bitset<N> vis;
int a[6], idx[6], n;
LL dist[6][N];

int read() {
	int res = 0;
	char ch = cin.get();
	for(; '0' > ch || ch > '9'; ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	return res;
}

void Dijkstra(const int rt, const int id) {
	vis.reset();
	auto& dis = dist[id];
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
	q.push({dis[rt], rt});
	while(!q.empty()) {
		const int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: G[u])
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	n = read(); int m = read();
	a[0] = 1;
	for(int i = 1; i <= 5; ++i)
		a[i] = read();
	for(int u, v, w; m--; ) {
		u = read(); v = read(); w = read();
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	sort(a + 1, a + 5 + 1);
	for(int i = 0; i <= 5; ++i) {
		Dijkstra(a[i], i);
		idx[i] = i;
	}
	LL ans = 0x3f3f3f3f3f3f3f3f;
	do {
		LL tot = 0;
		for(int i = 0; i < 5; ++i)
			tot += dist[idx[i]][a[idx[i + 1]]];
		ans = min(ans, tot);
	} while(next_permutation(idx + 1, idx + 5 + 1));
	cout << ans << endl;
	return 0;
}