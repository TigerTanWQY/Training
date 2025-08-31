#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
int n;
LL a[N], T[N << 2], tag[N << 2];

auto ls = [](int u) { return u << 1; };
auto rs = [](int u) { return u << 1 | 1; };

void update(int u)
{ T[u] = T[ls(u)] + T[rs(u)]; }
void settag(int u, int L, int R, LL t) {
	T[u] += t * (R - L + 1);
	tag[u] += t;
}
void pushdown(int u, int L, int R) {
	if(!tag[u])
		return;
	int M = (L + R) >> 1;
	settag(ls(u), L, M, tag[u]);
	settag(rs(u), M + 1, R, tag[u]);
	tag[u] = 0;
}

void buildTree(int u, int L, int R) {
	if(L == R) {
		T[u] = a[L];
		return;
	}
	int M = (L + R) >> 1;
	buildTree(ls(u), L, M);
	buildTree(rs(u), M + 1, R);
	update(u);
}

void mdf(int u, int L, int R, int qL, int qR, LL w) {
	if(qL <= L && R <= qR) {
		settag(u, L, R, w);
		return;
	}
	int M = (L + R) >> 1;
	pushdown(u, L, R);
	if(qR <= M)
		mdf(ls(u), L, M, qL, qR, w);
	else if(qL > M)
		mdf(rs(u), M + 1, R, qL, qR, w);
	else {
		mdf(ls(u), L, M, qL, M, w);
		mdf(rs(u), M + 1, R, M + 1, qR, w);
	}
	update(u);
}

LL qry(int u, int L, int R, int qL, int qR) {
	if(qL <= L && R <= qR)
		return T[u];
	pushdown(u, L, R);
	int M = (L + R) >> 1;
	if(qR <= M)
		return qry(ls(u), L, M, qL, qR);
	else if(qL > M)
		return qry(rs(u), M + 1, R, qL, qR);
	else
		return qry(ls(u), L, M, qL, M) + qry(rs(u), M + 1, R, M + 1, qR);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	buildTree(1, 1, n);
	for(int op, qL, qR; _q--; ) {
		cin >> op >> qL >> qR;
		if(qL > qR)
			swap(qL, qR);
		if(op == 1) {
			LL w; cin >> w;
			mdf(1, 1, n, qL, qR, w);
		} else
			cout << qry(1, 1, n, qL, qR) << '\n';
	}
	cout.flush();
	return 0;
}
