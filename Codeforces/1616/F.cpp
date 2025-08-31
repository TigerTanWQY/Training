#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 260;
int a[100003][N], G[N][N], ans[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		memset(G, 0, sizeof G);
		memset(a, 0, sizeof a);
		int cnt = 0, id = 0;
		cin >> n >> m;
		for(int i = 1, u, v, w; i <= m; ++i) {
			cin >> u >> v >> w;
			if(w != -1) {
				++cnt;
				a[cnt][i] = 1;
				a[cnt][m + 1] = w % 3;
			}
			G[u][v] = G[v][u] = i;
		}
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j)
				for(int k = j + 1; k <= n; ++k)
					if(G[i][j] && G[j][k] && G[k][i]) {
						++cnt;
						a[cnt][G[i][j]] = a[cnt][G[j][k]] = a[cnt][G[k][i]] = 1;
					}
		for(int i = 1; i <= m; ++i) {
			int nw = 0;
			for(int j = id + 1; j <= cnt; ++j)
				if(a[j][i])
					nw = j;
			if(!nw) {
				ans[i] = 0;
				continue;
			}
			swap(a[++id], a[nw]);
			if(a[id][i] != 1)
				for(int j = i; j <= m + 1; ++j)
					a[id][j] = 3 - a[id][j];
			for(int j = 1; j <= cnt; ++j)
				if(id != j && a[j][i]) {
					int x = a[j][i];
					for(int k = i; k <= m + 1; ++k)
						a[j][k] = (a[j][k] - x * a[id][k] + 9) % 3;
				}
		}
		bool flg = false;
		for(int i = id + 1; i <= cnt; ++i)
			if(a[i][m + 1]) {
				cout << "-1";
				flg = true;
				break;
			}
		if(flg)
			continue;
		for(int i = 1; i <= id; ++i) {
			int j = i;
			for(; !a[i][j]; ++j);
			ans[j] = a[i][m + 1];
		}
		for(int i = 1; i <= m; ++i)
			cout << (ans[i]? ans[i]: 3) << ' ';
	}
	cout.flush(); return 0;
}
