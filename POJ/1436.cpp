#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 8003;
struct Seg {
	int y1, y2, x, id;
	bool operator<(const Seg& A) const
	{ return x < A.x; }
} a[N];
bool vis[N][N];
int T[N << 3];

void pushdown(int u) {
	if(!T[u])
		return;
	T[u << 1] = T[u << 1 | 1] = T[u];
	T[u] = 0;
}

void update(int v, int L, int R, int l, int r, int u) {
	if(L <= l && r <= R) {
		T[u] = v;
		return;
	}
	pushdown(u);
	int M = (l + r) >> 1;
	if(M >= L)
		update(v, L, R, l, M, u << 1);
	if(M < R)
		update(v, L, R, M + 1, r, u << 1 | 1);
}

void query(int v, int L, int R, int l, int r, int u) {
	if(T[u]) {
		vis[v][T[u]]=1;
		return;
	} else if(l == r)
		return;
	pushdown(u);
	int M = (l + r) >> 1;
	if(M >= L)
		query(v, L, R, l, M, u << 1);
	if(M < R)
		query(v, L, R, M + 1, r, u << 1 | 1);
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		memset(vis, 0, sizeof(vis));
		memset(T, 0, sizeof(T));
		cin >> n;
		int maxn = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].y1 >> a[i].y2 >> a[i].x;
			a[i].y1 *= 2;
			a[i].y2 *= 2;
			a[i].id = i;
			maxn = max(maxn, a[i].y2);
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i) {
			query(a[i].id, a[i].y1, a[i].y2, 0, maxn, 1);
			update(a[i].id, a[i].y1, a[i].y2, 0, maxn, 1);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(vis[i][j])
					for(int k = 1; k <= n; ++k)
						if(vis[i][k] && vis[j][k])
							++ans;
		cout << ans;
	}
	cout.flush(); return 0;
}
