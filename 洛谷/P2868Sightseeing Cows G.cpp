#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

const int N = 1003;
vector<pair<int, int>> G[N];
int cnt[N], n;
bool vis[N];
int a[N];
double dis[N];

bool SPFA(const double& eps) {
	for(int i = 1; i <= n; ++i) {
		vis[i] = false;
		dis[i] = 0x3f3f3f3f;
		cnt[i] = 0;
	}
	stack<int> q;
	for(int i = 1; i <= n; ++i) {
		q.push(i);
		dis[i] = 0;
		vis[i] = true;
		++cnt[i];
	}
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		vis[u] = false;
		for(const auto& p: G[u]) {
			int v = p.first, w = p.second;
			if(dis[v] > dis[u] - a[u] + eps * w) {
				dis[v] = dis[u] - a[u] + eps * w;
				if(!vis[v]) {
					q.push(v);
					vis[v] = true;
					if(++cnt[v] > n + 1)
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
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	double L = 0, R = 1000001;
	for(int _ = 100; _--; ) {
		double M = (L + R) / 2;
		if(SPFA(M))
			L = M;
		else
			R = M;
	}
	cout << fixed << setprecision(2) << L;
	return 0;
}