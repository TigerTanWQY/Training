#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
int a[N], n;
LL T[N << 2], tag[N << 2];

auto ls = [](int u){ return u << 1; };
auto rs = [](int u){ return ls(u) | 1; };

void update(int u)
{ T[u] = T[ls(u)] + T[rs(u)]; }
void settag(int u, int l, int r, LL t) {
	T[u] += t * (r - l + 1);
	tag[u] += t;
}
void pushdown(int u, int l, int r) {
	if(!tag[u])
		return;
	int M = (l + r) >> 1;
	settag(ls(u), l, M, tag[u]);
	settag(rs(u), M + 1, r, tag[u]);
	tag[u] = 0;
}

void buildTree(int u, int l, int r) {
	if(l == r) {
		T[u] = a[l];
		return;
	}
	int M = (l + r) >> 1;
	buildTree(ls(u), l, M);
	buildTree(rs(u), M + 1, r);
	update(u);
}

void mdf(int u, int l, int r, int L, int R, LL w) {
	if(L <= l && r <= R) {
		settag(u, l, r, w);
		return;
	}
	int M = (l + r) >> 1;
	pushdown(u, l, r);
	if(R <= M)
		mdf(ls(u), l, M, L, R, w);
	else if(L > M)
		mdf(rs(u), M + 1, r, L, R, w);
	else {
		mdf(ls(u), l, M, L, M, w);
		mdf(rs(u), M + 1, r, M + 1, R, w);
	}
	update(u);
}

LL qry(int u, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return T[u];
	pushdown(u, l, r);
	int M = (l + r) >> 1;
	if(R <= M)
		return qry(ls(u), l, M, L, R);
	else if(L > M)
		return qry(rs(u), M + 1, r, L, R);
	else
		return qry(ls(u), l, M, L, M) + qry(rs(u), M + 1, r, M + 1, R);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	buildTree(1, 1, n);
	for(int L, R; _q--; ) {
		char op; cin >> op >> L >> R;
		if(op == 'C') {
			LL w; cin >> w;
			mdf(1, 1, n, L, R, w);
		} else
			cout << qry(1, 1, n, L, R) << '\n';
	}
	cout.flush();
	return 0;
}
