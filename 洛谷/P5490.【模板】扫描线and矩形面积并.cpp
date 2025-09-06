#include <bits/stdc++.h>
#define Ls (x << 1)
#define Rs (x << 1 | 1)
using namespace std;
using LL = long long;
#define y1 asdfg

constexpr const int N = 1e6 + 3;
LL X[N << 1];

struct Data {
	LL l, r, h;
	int tag;
	bool operator<(const Data &A) const
	{ return h < A.h; }
} line[N << 1];

struct SegTree {
	int l, r, tot;
	LL len;
} T[N << 2];

void build(int x, int l, int r) {
	T[x].l = l; T[x].r = r;
	T[x].len = 0; T[x].tot = 0;
	if(l == r)
		return;
	int M = (l + r) >> 1;
	build(Ls, l, M);
	build(Rs, M + 1, r);
	return;
}

void pushup(int x) {
	int l = T[x].l, r = T[x].r;
	T[x].len = (T[x].tot? X[r + 1] - X[l]: T[Ls].len + T[Rs].len);
}

void mdf(int x, LL L, LL R, int c) {
	int l = T[x].l, r = T[x].r;
	if(X[r + 1] <= L || R <= X[l])
		return;
	if(L <= X[l] && X[r + 1] <= R) {
		T[x].tot += c;
		pushup(x);
		return;
	}
	mdf(Ls, L, R, c);
	mdf(Rs, L, R, c);
	pushup(x);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1, x1, y1, x2, y2; i <= n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		X[2 * i - 1] = x1; X[2 * i] = x2;
		line[2 * i - 1] = {x1, x2, y1, 1};
		line[2 * i] = {x1, x2, y2, -1};
	}
	n <<= 1;
	sort(line + 1, line + n + 1);
	sort(X + 1, X + n + 1);
	build(1, 1, unique(X + 1, X + n + 1) - X - 2);
	LL ans = 0;
	for(int i = 1; i < n; ++i) {
		mdf(1, line[i].l, line[i].r, line[i].tag);
		ans += T[1].len * (line[i + 1].h - line[i].h);
	}
	cout << ans << endl;
	return 0;
}
