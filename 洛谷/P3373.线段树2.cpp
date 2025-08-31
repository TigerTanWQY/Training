#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
int p;
struct Tag {
	LL mul, add;
	Tag friend operator+(const Tag& t1, const Tag& t2)
	{ return {t1.mul * t2.mul % p, (t1.add * t2.mul % p + t2.add) % p}; }
	Tag& operator+=(const Tag& t2) {
		*this = *this + t2;
		return *this;
	}
};
struct Node {
	int L, R;
	LL val;
	Tag t;
	int sz;
} seg[N * 4];
LL a[N];

void update(const int u)
{ seg[u].val = (seg[u * 2].val + seg[u * 2 + 1].val) % p; }

void settag(const int u, const Tag& t) {
	seg[u].t += t;
	seg[u].val = (seg[u].val * t.mul % p + seg[u].sz * t.add % p) % p;
}

void pushdown(const int u) {
	if(seg[u].t.mul != 1 || seg[u].t.add != 0) {
		settag(u * 2, seg[u].t);
		settag(u * 2 + 1, seg[u].t);
		seg[u].t.mul = 1;
		seg[u].t.add = 0;
	}
}

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R; seg[u].t = {1, 0}; seg[u].sz = R - L + 1;
	if(L == R) {
		seg[u].val = a[L];
		return;
	}
	int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	update(u);
}

LL query(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R)
		return seg[u].val % p;
	pushdown(u);
	int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		return query(u * 2, L, R);
	else if(L > M)
		return query(u * 2 + 1, L, R);
	else
		return (query(u * 2, L, R) + query(u * 2 + 1, L, R)) % p;
}

void modify(const int u, const int L, const int R, const Tag& t) {
	if(L <= seg[u].L && seg[u].R <= R) {
		settag(u, t);
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
	cin >> n >> m >> p;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	buildTree(1, 1, n);
	for(int op, x, y, k; m--; ) {
		cin >> op >> x >> y;
		if(op <= 2) {
			cin >> k;
			if(op == 1)
				modify(1, x, y, {k, 0});
			else
				modify(1, x, y, {1, k});
		} else
			cout << query(1, x, y) << '\n';
	}
	cout.flush();
	return 0;
}