#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
struct Edge // 手搓链式前向星
{ int to, nxt, w; }
G[N];
queue<int> p[N];
int hd[N], idx = 0, id[N], n;
LL dis[N], f[N];

inline int adde(const int u, const int v, const int w) {
	++idx;
	G[idx].to = v;
	G[idx].w = w;
	G[idx].nxt = hd[u];
	hd[u] = idx;
	return idx;
}

inline void Dijkstra() {
	for(int i = 0; i <= n; ++i)
		dis[i] = 0x3f3f3f3f3f3f3f3f;
	dis[1] = 0;
	__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
	q.push({dis[1], 1});
	while(!q.empty()){
		auto [w, u] = q.top();
		q.pop();
		if(dis[u] < w)
			continue;
		for(int e = hd[u]; e > 0; e = G[e].nxt){
			const int v = G[e].to;
			LL nw = dis[u] + G[e].w;
			if(dis[v] > nw) {
				dis[v] = nw;
				q.push({nw, v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, Q;
	cin >> n >> m >> Q;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		id[i] = adde(u, v, w);
	}
	Dijkstra();
	for(int q = 1, op, c; q <= Q; q++) {
		cin >> op >> c;
		if(op == 1)
			cout << (dis[c] >= 0x3f3f3f3f3f3f3f3f / 2? -1: dis[c]) << '\n';
		else {
			for(int _c = 0, v; _c < c; ++_c) {
				cin >> v;
				++G[id[v]].w;
			}
			for(int i = 1; i <= n; ++i)
				f[i] = c + 1;
			f[1] = 0;
			p[0].push(1);
			for(int d = 0; d <= c; d++) {
				while(!p[d].empty()) {
					const int u = p[d].front();
					p[d].pop();
					if(f[u] < d)
						continue;
					for(int e = hd[u]; e > 0; e = G[e].nxt) {
						const int v = G[e].to;
						LL nw = dis[u] + f[u] + G[e].w - dis[v];
						if(nw < f[v]) {
							f[v] = nw;
							p[nw].push(v);
						}
					}
				}
			}
			for(int i = 1; i <= n; ++i)
				dis[i] += f[i];
			for(int d = 0; d <= c; ++d)
				while(!p[d].empty())
					p[d].pop();
		}
	}
	cout.flush();
	return 0;
}