#include <bits/stdc++.h>
using namespace std;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

constexpr const int N = 4e5 + 3;
pair<int, int> e[N];
stack<array<int, 3>> stk;
vector<int> G[N];
int fa[N], dep[N], n;

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

void mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(dep[x] > dep[y])
		swap(x, y);
	stk.push({x, y, dep[x] == dep[y]});
	fa[x] = y;
	if(dep[x] == dep[y])
		++dep[y];
}

void mdf(int u, int L, int R, int qL, int qR, int x) {
	if(L > qR || R < qL)
		return;
	if(qL <= L && R <= qR)
	{ G[u].push_back(x); return; }
	int M = L + R >> 1;
	mdf(ls(u), L, M, qL, qR, x);
	mdf(rs(u), M + 1, R, qL, qR, x);
}

void work(int u, int L, int R) {
	int ans = 1, lst = stk.size();
	for(const auto& i: G[u]) {
		int x = e[i].first, y = e[i].second;
		if(fnd(x) == fnd(y)) {
			for(int k = L; k <= R; ++k)
				cout << "No\n";
			ans = 0;
			break;
		}
		mrge(x, y + n);
		mrge(y, x + n);
	}
	if(ans)
		if(L == R)
			cout << "Yes\n";
		else {
			int M = L + R >> 1;
			work(ls(u), L, M);
			work(rs(u), M + 1, R);
		}
	for(; stk.size() > lst; stk.pop()) {
		int x = stk.top()[0], y = stk.top()[1], add = stk.top()[2];
		dep[fa[x]] -= add;
		fa[x] = x;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m, k;
	cin >> n >> m >> k;
	for(int i = 1, x, y, L, R; i <= m; ++i) {
		cin >> x >> y >> L >> R; ++L;
		mdf(1, 1, k, L, R, i);
		e[i] = {x, y};
	}
	for(int i = 1; i <= 2 * n; ++i)
	{ fa[i] = i; dep[i] = 1; }
	work(1, 1, k);
	cout.flush(); return 0;
}
