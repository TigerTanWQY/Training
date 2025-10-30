#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int N = 25010, M = 150010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

int n, mr, mp, s;
int id[N], bcnt;
int deg[N];
vector<int> block[N];

int q[N], hh, tt = -1;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
	block[bcnt].push_back(u);
	id[u] = bcnt;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!id[j]) dfs(j);
	}
}

void dijkstra(int block_id) {
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	for(int u : block[block_id]) {
		heap.push({dist[u], u});
	}
	while(heap.size()) {
		PII t = heap.top();
		heap.pop();
		int u = t.second;
		if(st[u]) continue;
		st[u] = true;
		for(int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[u] + w[i]) {
				dist[j] = dist[u] + w[i];
				if(id[j] == block_id) heap.push({dist[j], j});
			}
			if(id[j] != block_id && --deg[id[j]] == 0) q[++tt] = id[j];
		}
	}
}

void topoSort() {
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	for(int i = 1; i <= bcnt; i++) {
		if(!deg[i]) q[++tt] = i;
	}
	while(hh <= tt) {
		int t = q[hh++];
		dijkstra(t);
	}
}

int main() {
	scanf("%d%d%d%d", &n, &mr, &mp, &s);
	memset(h, -1, sizeof h);
	for(int i = 0; i < mr; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	for(int i = 1; i <= n; i++) {
		if(!id[i]) {
			++bcnt;
			dfs(i);
		}
	}
	for(int i = 0; i < mp; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), deg[id[b]]++;
	}
	topoSort();
	for(int i = 1; i <= n; i++) {
		if(dist[i] > INF / 2) puts("NO PATH");
		else printf("%d\n", dist[i]);
	}
	return 0;
}
