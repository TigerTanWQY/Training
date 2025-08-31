#include <bits/stdc++.h>
#define L(i, j, k, l) for (int i = (j); i <= (k); i += (l))
#define R(i, j, k, l) for (int i = (j); i >= (j); i -= (l))
using namespace std;

constexpr const int N = 1e5 + 3, P = 1e9 + 7;
struct Matrix {
	int a[2][2];
	Matrix(int p = 0, int q = 0, int x = 0, int y = 0) {a[0][0] = p, a[0][1] = q, a[1][0] = x, a[1][1] = y;}
	Matrix operator*(Matrix b) {
		Matrix c;
		L(k, 0, 1, 1) L(i, 0, 1, 1) L(j, 0, 1, 1) c.a[i][j] = (c.a[i][j] + 1ll * a[i][k] * 1ll * b.a[k][j] % P) % P;
		return c;
	}
};
struct Sgt {
	int l, r, tag;
	Matrix res0, res1;
} t[N << 2];
char s[N];

void pushup(int p) {
	Sgt &u = t[p], &l = t[p << 1], &r = t[p << 1 | 1];
	u.res0 = l.res0 * r.res0, u.res1 = l.res1 * r.res1;
}
void pushdown(int p) {
	if (t[p].tag) swap(t[p << 1].res0, t[p << 1].res1), t[p << 1].tag ^= 1, swap(t[p << 1 | 1].res0, t[p << 1 | 1].res1), t[p << 1 | 1].tag ^= 1, t[p].tag = 0;
}
void build(int p, int l, int r) {
	t[p].l = l, t[p].r = r;
	if (l == r) {
		t[p].res0 = Matrix(1, 0, 1, 1);
		t[p].res1 = Matrix(1, 1, 0, 1);
		if (s[l] == 'B')
			swap(t[p].res0, t[p].res1);
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void modify(int p, int l, int r) {
	if (l <= t[p].l && t[p].r <= r) {
		swap(t[p].res0, t[p].res1), t[p].tag ^= 1;
		return;
	}
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) modify(p << 1, l, r);
	if (r > mid) modify(p << 1 | 1, l, r);
	pushup(p);
}

Sgt merge(Sgt l, Sgt r) {
	Sgt u;
	u.res0 = l.res0 * r.res0, u.res1 = l.res1 * r.res1;
	return u;
}

Sgt query(int p, int l, int r) {
	if (l <= t[p].l && t[p].r <= r) return t[p];
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l > mid) return query(p << 1 | 1, l, r);
	if (r <= mid) return query(p << 1, l, r);
	return merge(query(p << 1, l, r), query(p << 1 | 1, l, r));
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q >> s;
	for(int i = n; i; --i)
		swap(s[i], s[i - 1]);
	build(1, 1, n);
	for(int op, l, r; q--; ) {
		cin >> op >> l >> r;
		if(op == 1)
			modify(1, l, r);
		else {
			Matrix a;
			cin >> a.a[0][0] >> a.a[0][1];
			a = a * query(1, l, r).res0;
			cout << a.a[0][0] << ' ' << a.a[0][1] << '\n';
		}
	}
	cout.flush();
	return 0;
}
