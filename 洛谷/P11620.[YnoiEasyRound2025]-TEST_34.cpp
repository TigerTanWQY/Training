#include <bits/stdc++.h>
using namespace std;
#define ls (u << 1)
#define rs (ls | 1)
#define M (L + R >> 1)

constexpr const int N = 5e4 + 3;
int n;
unsigned a[N], c[N];
struct LineBase {
	unsigned d[32];
	void ist(unsigned x) {
		for(int i = 30; ~i; --i)
			if(x >> i & 1U)
				if(d[i])
					x ^= d[i];
				else {
					d[i] = x;
					return;
				}
	}
} T[N << 2];
LineBase mrge(LineBase x, const LineBase& y) {
	for(int i = 30; ~i; --i)
		if(y.d[i])
			x.ist(y.d[i]);
	return x;
}
void buildTree(int u = 1, int L = 1, int R = n) {
	for(int i = L; i <= R; ++i)
		T[u].ist(a[i]);
	if(L == R)
		return;
	buildTree(ls, L, M);
	buildTree(rs, M + 1, R);
	T[u] = mrge(T[ls], T[rs]);
}
void mdf(int id, unsigned w, int u = 1, int L = 1, int R = n) {
	if(L == R) {
		memset(T[u].d, 0, sizeof T[u].d);
		T[u].ist(a[L] ^= w);
		return;
	}
	if(id <= M)
		mdf(id, w, ls, L, M);
	else
		mdf(id, w, rs, M + 1, R);
	T[u] = mrge(T[ls], T[rs]);
}
LineBase qry(int qL, int qR, int u = 1, int L = 1, int R = n) {
	if(L == qL && R == qR)
		return T[u];
	if(M >= qR)
		return qry(qL, qR, ls, L, M);
	else if(M < qL)
		return qry(qL, qR, rs, M + 1, R);
	else
		return mrge(qry(qL, M, ls, L, M), qry(M + 1, qR, rs, M + 1, R));
}
int lb(int x)
{ return x & -x; }
void upd(int i, unsigned w) {
	for(; i <= n; i += lb(i))
		c[i] ^= w;
}
unsigned qry(int i) {
	unsigned res = 0;
	for(; i; i -= lb(i))
		res ^= c[i];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = n; i >= 2; --i)
		a[i] ^= a[i - 1];
	for(int i = 1; i <= n; ++i)
		upd(i, a[i]);
	buildTree();
	for(int op, L, R; m--; ) {
		unsigned w;
		cin >> op >> L >> R >> w;
		if(op == 1) {
			upd(L, w);
			mdf(L, w);
			if(R < n) {
				upd(R + 1, w);
				mdf(R + 1, w);
			}
		} else {
			auto k = qry(L);
			if(L == R)
				cout << max(k ^ w, w);
			else {
				LineBase res = qry(L + 1, R);
				res.ist(k);
				for(int i = 30; ~i; --i)
					if((w ^ res.d[i]) > w)
						w ^= res.d[i];
				cout << w;
			}
			cout.put('\n');
		}
	}
	cout.flush(); return 0;
}
