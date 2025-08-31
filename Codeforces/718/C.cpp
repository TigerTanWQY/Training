#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr const int P = 1e9 + 7, N = 1e5 + 3;
struct Matrix {
	int a[4][4];
	void clear()
	{ memset(a, 0, sizeof(a)); }
	void init()
	{ for(int i = 0; i < 4; ++i) a[i][i] = 1; }
	bool empty()
	{ return a[1][1] == 1 && a[1][2] == 0 && a[2][1] == 0 && a[2][2] == 1; }
	Matrix operator*(const Matrix &y) const {
		Matrix res; res.clear();
		for(int k = 1; k <= 2; ++k)
			for(int i = 1; i <= 2; ++i)
				for(int j = 1; j <= 2; ++j)
					res.a[i][j] = (res.a[i][j] + a[i][k] * y.a[k][j] % P) % P;
		return res;
	}
	friend Matrix operator+(Matrix a, Matrix b) {
		Matrix res; res.clear();
		for(int i = 1; i <= 2; ++i)
			for(int j = 1; j <= 2; ++j)
				res.a[i][j] = (a.a[i][j] + b.a[i][j]) % P;
		return res;
	}
	Matrix& operator*=(const Matrix& y) {
		*this = *this * y;
		return *this;
	}
	Matrix& operator+=(const Matrix& b) {
		*this = *this + b;
		return *this;
	}
} T[N << 2], tag[N << 2], a1, a2;
Matrix qpow(Matrix a, int b) {
	Matrix res; res.clear(); res.init();
	for(; b; a *= a, b >>= 1)
		if(b & 1)
			res *= a;
	return res;
}
int val[N];
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
void update(int u)
{ T[u] = T[ls(u)] + T[rs(u)]; }

void buildTree(int u, int l, int r) {
	T[u].clear(); tag[u].clear(); tag[u].init();
	if(l == r) {
		T[u] = a2 * qpow(a1, val[l] - 1);
		return;
	}
	int M = (l + r) >> 1;
	buildTree(ls(u), l, M);
	buildTree(rs(u), M + 1, r);
	update(u);
}

void pushdown(int u) {
	if(tag[u].empty())
		return;
	T[ls(u)] *= tag[u]; tag[ls(u)] *= tag[u];
	T[rs(u)] *= tag[u]; tag[rs(u)] *= tag[u];
	tag[u].clear(); tag[u].init();
}

void mdf(int u, int ql, int qr, int l, int r, Matrix w) {
	if(ql <= l && r <= qr) {
		T[u] *= w; tag[u] *= w;
		return;
	}
	pushdown(u);
	int M = (l + r) >> 1;
	if(ql <= M)
		mdf(ls(u), ql, qr, l, M, w);
	if(M < qr)
		mdf(rs(u), ql, qr, M + 1, r, w);
	update(u);
}

Matrix qry(int u, int ql, int qr, int l, int r) {
	if(ql <= l && r <= qr)
		return T[u];
	pushdown(u);
	Matrix res; res.clear();
	int M = (l + r) >> 1;
	if(ql <= M)
		res += qry(ls(u), ql, qr, l, M);
	if(M < qr)
		res += qry(rs(u), ql, qr, M + 1, r);
	return res;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	a1.clear(); a2.clear();
	a1.a[1][1] = a2.a[1][1] = a1.a[1][2] = a2.a[1][2] = a1.a[2][1] = 1;
	a2.a[2][1] = a1.a[2][2] = a2.a[2][2] = 0;
	int n, _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i)
		cin >> val[i];
	buildTree(1, 1, n);
	for(int op, l, r, w; _q--; ) {
		cin >> op >> l >> r;
		if(op == 1) {
			cin >> w;
			mdf(1, l, r, 1, n, qpow(a1, w));
		} else
			cout << qry(1, l, r, 1, n).a[1][2] % P << '\n';
	}
	cout.flush();
	return 0;
}
