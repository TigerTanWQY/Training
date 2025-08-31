#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
struct Node {
	int L, R;
	LL val, t;
} seg[N * 4];
LL a[N];

void update(const int u)
{ seg[u].val = seg[u * 2].val + seg[u * 2 + 1].val; }

void settag(const int u, const int L, const int R, const LL t) {
	seg[u].val += t * (R - L + 1);
	seg[u].t += t;
}

void pushdown(const int u) {
	if(seg[u].t != 0) {
		const int M = (seg[u].L + seg[u].R) / 2;
		settag(u * 2, seg[u].L, M, seg[u].t);
		settag(u * 2 + 1, M + 1, seg[u].R, seg[u].t);
		seg[u].t = 0;
	}
}

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R;
	if(L == R) {
		seg[u].val = a[L];
		seg[u].t = 0;
		return;
	}
	int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	update(u);
}

LL query(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R)
		return seg[u].val;
	pushdown(u);
	int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		return query(u * 2, L, R);
	else if(L > M)
		return query(u * 2 + 1, L, R);
	else
		return query(u * 2, L, M) + query(u * 2 + 1, M + 1, R);
}

void modify(const int u, const int L, const int R, const LL t) {
	if(L <= seg[u].L && seg[u].R <= R) {
		settag(u, seg[u].L, seg[u].R, t);
		return;
	}
	int M = (seg[u].L + seg[u].R) / 2;
	pushdown(u);
	if(R <= M)
		modify(u * 2, L, R, t);
	else if(L > M)
		modify(u * 2 + 1, L, R, t);
	else {
		modify(u * 2, L, R, t);
		modify(u * 2 + 1, L, R, t);
	}
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
	for(int op, x, y, k; m--; ) {
		cin >> op >> x >> y;
		if(op == 1) {
			cin >> k;
			modify(1, x, y, k);
		} else
			cout << query(1, x, y) << '\n';
	}
	cout.flush();
	return 0;
}