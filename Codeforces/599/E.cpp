#include <cstdio>
#include <cstring>
using namespace std;
using LL = long long;

constexpr const int N = 13 + 1;
bool G[N][N];
int n, m, q;
struct Edge
{ int u, v; }
e[N];
struct node
{ int u, v, w; }
a[103];
LL f[N][1 << N];

int read() {
	int res = 0;
	char ch = getchar();
	for(; '0' > ch || ch > '9'; ch = getchar());
	for(; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

bool check(const int x, const int s)
{ return s & 1 << x; }

LL dfs(const int u, int s) {
	if(~f[u][s])
		return f[u][s];
	LL res = 0;
	s -= 1 << u;
	int pos;
	for(pos = 0; pos < n; ++pos)
		if(check(pos, s))
			break;
	for(int j = s; j; j = (j - 1) & s)
		if(check(pos, j)) {
			bool flag = true;
			for(int i = 1; i <= q; ++i)
				if(a[i].w == u && check(a[i].u, j) && check(a[i].v, j)) {
					flag = false;
					break;
				}
			if(!flag)
				continue;
			for(int i = 1; i <= q; ++i)
				if(check(a[i].w, j) && (!check(a[i].u, j) || !check(a[i].v, j))) {
					flag = false;
					break;
				}
            if(!flag)
				continue;
			for(int i = 1; i <= m; ++i)
				if(e[i].u != u && e[i].v != u && (check(e[i].u, j) ^ check(e[i].v, j))) {
					flag = false;
					break;
				}
			if(!flag)
				continue;
			int v = 0, cnt = 0;
			for(int i = 0; i < n; ++i)
				if(G[u][i] && check(i, j)) {
					++cnt;
					v = i;
				}
			if(cnt > 1)
				continue;
			else if(cnt == 1)
				res += dfs(v, j) * dfs(u, s ^ j ^ (1 << u));
			else
				for(v = 0; v < n; ++v)
					if(check(v, j))
						res += dfs(v, j) * dfs(u, s ^ j ^ (1 << u));
		}
	return f[u][s] = res;
}

int main() {
	n = read(); m = read(); q = read();
	for(int i = 1; i <= m; ++i) {
		e[i].u = read() - 1; e[i].v = read() - 1;
		G[e[i].u][e[i].v] = G[e[i].v][e[i].u] = true;
	}
	for(int i = 1; i <= q; ++i) {
		a[i].u = read() - 1; a[i].v = read() - 1; a[i].w = read() - 1;
	}
	memset(f, -1, sizeof f);
	for(int i = 0; i < n; ++i)
		f[i][1 << i] = 1;
	printf("%lld", dfs(0, (1 << n) - 1));
	return 0;
}