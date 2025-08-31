#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 200'003;
struct Node
{ int L, R, maxn; }
seg[N * 4];
int a[N];

void update(const int u)
{ seg[u].maxn = max(seg[u * 2].maxn, seg[u * 2 + 1].maxn); }

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R;
	if(L == R) {
		seg[u].maxn = a[L];
		return;
	}
	int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	update(u);
}

int query(const int u, const int L, const int R, const int w) {
	if(L <= seg[u].L && seg[u].R <= R)
		if(seg[u].maxn < w)
			return -1;
		else {
			if(seg[u].L == seg[u].R)
				return seg[u].L;
			int M = (seg[u].L + seg[u].R) / 2;
			if(seg[u * 2].maxn >= w)
				return query(u * 2, L, M, w);
			else
				return query(u * 2 + 1, M + 1, R, w);
		}
	int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		return query(u * 2, L, R, w);
	else if(L > M)
		return query(u * 2 + 1, L, R, w);
	else {
		int pos = query(u * 2, L, M, w);
		if(pos == -1)
			return query(u * 2 + 1, M + 1, R, w);
		else
			return pos;
	}
}

void modify(const int u, const int x, const int w) {
	if(seg[u].L == seg[u].R) {
		seg[u].maxn = w;
		return;
	}
	int M = (seg[u].L + seg[u].R) / 2;
	if(x <= M)
		modify(u * 2, x, w);
	else
		modify(u * 2 + 1, x, w);
	update(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	buildTree(1, 1, n);
	for(int op, d; m--; ) {
		cin >> op;
		if(op == 1) {
			int x;
			cin >> x >> d;
			modify(1, x, d);
		} else {
			int L, R;
			cin >> L >> R >> d;
			cout << query(1, L, R, d) << '\n';
		}
	}
	cout.flush();
	return 0;
}