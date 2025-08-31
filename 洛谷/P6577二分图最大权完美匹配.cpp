#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int N = 503;
vector<pair<int, int>> G[N];
bool va[N], vb[N];
int match[N], n;
LL la[N], lb[N], w[N][N], d[N];

bool dfs(const int &x) { // 可以使用 BFS 优化时间复杂度 ^_^
	va[x] = 1;
	for(int y = 1; y <= n; ++y)
		if(!vb[y]) {
			if(la[x] + lb[y] - w[x][y] == 0) {
				vb[y] = 1;
				if(!match[y] || dfs(match[y])) {
					match[y] = x;
					return true;
				}
			}
			else
				d[y] = min(d[y], la[x] + lb[y] - w[x][y]);
		}
	return false;
}

LL KM() {
	for(int i = 1; i <= n; ++i) {
		la[i] = -INF;
		lb[i] = 0;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			la[i] = max(la[i], w[i][j]);
	for(int i = 1; i <= n; ++i)
		while(true) {
			memset(va, false, sizeof(va));
			memset(vb, false, sizeof(vb));
			memset(d, 0x3f, sizeof(d));
			if(dfs(i))
				break;
			LL delta = INF;
			for(int j = 1; j <= n; ++j)
				if(!vb[j])
					delta = min(delta, d[j]);
			for(int j = 1; j <= n; ++j) {
				if(va[j])
					la[j] -= delta;
				if(vb[j])
					lb[j] += delta;
			}
		}
	LL ret = 0;
	for(int i = 1; i <= n; ++i)
		ret += w[match[i]][i];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			w[i][j] = -INF;
	for(int y, c, h; m--; ) {
		cin >> y >> c >> h;
		w[y][c] = max(w[y][c], (LL)h);
	}
	cout << KM() << '\n';
	for(int i = 1; i <= n; ++i)
		cout << match[i] << ' ';
	return 0;
}
