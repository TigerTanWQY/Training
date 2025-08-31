#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
int p[N], dis[N];

int dfs(int u) {
	if(~dis[p[u]])
		return u;
	dis[p[u]] = dis[u] + 1;
	return dfs(p[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	string s;
	cin >> n >> m >> s; --m;
	int len = s.size();
	for(int i = 0; i < n; ++i)
	{ cin >> p[i]; --p[i]; }
	if(len <= 5) {
		int ans = m;
		for(int k = stoi(s); k--; ans = p[ans]);
		cout << ans + 1 << endl;
		return 0;
	}
	memset(dis, -1, sizeof(dis));
	dis[m] = 0;
	int pos = dfs(m), rlen = dis[pos] - dis[p[pos]] + 1, k = 0;
	for(int i = 0; i < len; ++i)
		k = (k * 10 + s[i] - '0') % rlen;
	k = ((k - dis[p[pos]]) % rlen + rlen) % rlen;
	int ans = p[pos];
	for(int i = 0; i < k; ++i)
		ans = p[ans];
	cout << ans + 1 << endl;
	return 0;
}
