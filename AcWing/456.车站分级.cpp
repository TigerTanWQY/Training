#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
bool G[N][N], vis[N];
int a[N], b[N], f[N], n;

int calc(const int& u) {
	if(~f[u])
		return f[u];
	f[u] = 0;
	for(int v = 1; v <= n; ++v)
		if(G[u][v])
			f[u] = max(f[u], calc(v) + 1);
	return f[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int len; m--; ) {
		cin >> len;
		for(int i = 0; i < len; ++i) {
			cin >> a[i];
			vis[a[i]] = true;
		}
		int cnt = 0;
		for(int i = a[0]; i <= a[len - 1]; ++i)
			if(!vis[i])
				b[cnt++] = i;
		for(int i = 0; i < len; ++i)
			for(int j = 0; j < cnt; ++j)
				G[a[i]][b[j]] = true;
		for(int u = 1; u <= n; ++u)
			vis[u] = false;
	}
	for(int u = 1; u <= n; ++u)
		f[u] = -1;
	int ans = 0;
	for(int u = 1; u <= n; ++u)
		ans = max(ans, calc(u));
	cout << ans + 1;
	return 0;
}