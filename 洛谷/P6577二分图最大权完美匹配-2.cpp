#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

const int N = 503;
bool vis[N];
int match[N], n;
LL a[N][N], slack[N], la[N], lb[N], d[N];

void find(const int &u) {
	memset(d, 0, sizeof(d));
	memset(slack, 0x3f, sizeof(slack));
	int y = 0;
	LL del;
	match[y] = u;
	for(int x, yy; true; ) {
		x = match[y];
		del = 0x3f3f3f3f3f3f3f3f;
		vis[y] = true;
		for(int i = 1; i <= n; ++i)
			if(!vis[i]) {
				if(slack[i] > la[x] + lb[i] - a[x][i]) {
					slack[i] = la[x] + lb[i] - a[x][i];
					d[i] = y;
				}
				if(slack[i] < del) {
					del = slack[i];
					yy = i;
				}
			}
		for(int i = 0; i <= n; ++i)
			if(vis[i]) {
				la[match[i]] -= del;
				lb[i] += del;
			}
			else
				slack[i] -= del;
		y = yy;
		if(match[y] == -1)
			break;
	}
	for(; y; y = d[y])
		match[y] = match[d[y]];
}

LL KM() {
	memset(match, -1, sizeof(match));
	memset(la, 0, sizeof(la));
	memset(lb, 0, sizeof(lb));
	for(int i = 1; i <= n; ++i) {
		memset(vis, false, sizeof(vis));
		find(i);
	}
	LL ret = 0;
	for(int i = 1; i <= n; ++i)
		if(match[i] != -1)
			ret += a[match[i]][i];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> n >> m;
	memset(a, -0x3f, sizeof(a));
	for(int y, c, h; m--; ) {
		cin >> y >> c >> h;
		a[y][c] = h;
	}
	cout << KM() << '\n';
	for(int i = 1; i <= n; ++i)
		cout << match[i] << ' ';
	return 0;
}
