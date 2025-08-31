#include <bits/stdc++.h>
using namespace std;
using U = unsigned;

constexpr const int P = 1e9 + 7, N = 1e5 + 3, B = 383;
struct LB {
	U a[5]{};
	bool ist(U x) {
		for(int i = 4; ~i; --i)
			if(x >> i & 1)
				if(a[i])
					x ^= a[i];
				else {
					a[i] = x;
					for(int j = 0; j < i; ++j)
						if(a[i] >> j & 1)
							a[i] ^= a[j];
					for(int j = i + 1; j < 5; ++j)
						if(a[j] >> i & 1)
							a[j] ^= a[i];
					return true;
				}
		return false;
	}
	U id()
	{ return (a[4] << 10) | (a[3] << 6) | (a[2] << 3) | (a[1] << 1) | a[0]; }
} b[B], c[N];
vector<pair<int, U>> G[N];
bool vis[N];
int rid[N], idx = 0, trs[B][B], f[N][B], bel[N], dis[N], ins[N], cnt = 0, con[N], fst[N], dfn[N], tim = 0, n, m;

void fnd(LB cur) {
	int hs = cur.id();
	if(rid[hs])
		return;
	else
		b[rid[hs] = ++idx] = cur;
	for(U i = 1; i < 32; ++i) {
		LB nxt = cur;
		if(nxt.ist(i))
			fnd(nxt);
	}
}
void dfs(int u, int fa) {
	bel[u] = cnt; dfn[u] = ++tim;
	for(const auto& [v, w]: G[u]) {
		if(v == 1)
			continue;
		if(!bel[v]) {
			dis[v] = dis[u] ^ w;
			dfs(v, u);
		} else if(v != fa && dfn[u] > dfn[v])
			ins[cnt] &= c[cnt].ist(dis[u] ^ dis[v] ^ w);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	fnd(*new(LB));
	for(int i = 1; i <= idx; ++i)
		for(int j = 1; j <= idx; ++j) {
			LB tmp = b[i];
			bool flg = true;
			for(int k = 0; k < 5; ++k)
				if(b[j].a[k])
					flg &= tmp.ist(b[j].a[k]);
			if(flg)
				trs[i][j] = rid[tmp.id()];
		}
	for(int u, v; m--; ) {
		U w;
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(const auto& [v, w]: G[1])
		if(!bel[v]) {
			++cnt; ins[cnt] = true;
			fst[cnt] = v; con[cnt] = w;
			dfs(v, -1);
		} else
			for(const auto& [y, z]: G[v])
				if(y == fst[bel[v]]){
					vis[bel[v]] = true;
					con[bel[v]] ^= z ^ w;
					break;
				}
	f[0][rid[0]] = 1;
	for(int i = 1; i <= cnt; ++i) {
		for(int j = 1; j <= idx; ++j)
			f[i][j] = f[i - 1][j];
		if(!ins[i])
			continue;
		if(!vis[i]) {
			int id = rid[c[i].id()];
			for(int j = 1; j <= idx; ++j)
				if(trs[j][id])
					f[i][trs[j][id]] = (f[i][trs[j][id]] + f[i - 1][j]) % P;
		} else {
			int id1 = rid[c[i].id()];
			bool flg = c[i].ist(con[i]);
			int id2 = rid[c[i].id()];
			for(int j = 1; j <= idx; ++j) {
				if(trs[j][id1])
					f[i][trs[j][id1]] = (f[i][trs[j][id1]] + 2 * f[i - 1][j] % P) % P;
				if(flg && trs[j][id2])
					f[i][trs[j][id2]] = (f[i][trs[j][id2]] + f[i - 1][j]) % P;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= idx; ++i)
		ans = (ans + f[cnt][i]) % P;
	cout << ans << endl;
	return 0;
}
