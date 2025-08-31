#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 53;
bool f[33][N][N];
int n;
LL dis[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	memset(dis, 0x3f, sizeof(dis));
	for(int u = 1; u <= n; ++u)
		dis[u][u] = 0;
	for(int u, v; m--; ) {
		cin >> u >> v;
		f[0][u][v] = true;
		dis[u][v] = (u != v);
	}
	for(int s = 1; s <= 30; ++s)
		for(int k = 1; k <= n; ++k)
			for(int u = 1; u <= n; ++u)
				for(int v = 1; v <= n; ++v)
					if(f[s - 1][u][k] && f[s - 1][k][v]) {
						f[s][u][v] = true;
						dis[u][v] = (u != v);
					}
	for(int k = 1; k <= n; ++k)
		for(int u = 1; u <= n; ++u)
			for(int v = 1; v <= n; ++v)
				dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
	cout << dis[1][n];
	cout << endl;
	return 0;
}