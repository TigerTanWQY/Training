#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int N = 1'350'003;
unordered_map<char, int> trie[N];
string a[N];
int idx[N], fa[19][N], d[N], cnt = 0;

void ist(const string& s, const int& i) {
	int u = 0;
	for(const auto& ch: s) {
		if(!trie[u].count(ch)) {
			trie[u][ch] = ++cnt;
			fa[0][cnt] = u;
			d[cnt] = d[u] + 1;
		}
		u = trie[u][ch];
	}
	idx[i] = u;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		ist(a[i], i);
	}
	for(int i = 1; i <= 16; ++i)
		for(int u = 1; u <= cnt; ++u)
			if(fa[i - 1][u])
				fa[i][u] = fa[i - 1][fa[i - 1][u]];
	cin >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		u = idx[u];
		v = idx[v];
		if(d[u] < d[v])
			swap(u, v);
		int tol = d[u] - d[v];
		for(int i = 0; tol && i <= 16; ++i, (tol >>= 1))
			if(tol & 1)
				u = fa[i][u];
		if(u == v) {
			cout << d[u] << '\n';
			continue;
		}
		for(int i = 16; i >= 0; --i)
			if(fa[i][u] != fa[i][v]) {
				u = fa[i][u];
				v = fa[i][v];
			}
		cout << d[fa[0][u]] << '\n';
	}
	return 0;
}