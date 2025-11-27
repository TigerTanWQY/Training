#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define M (L+R >> 1)
#define ls (u<<1)
#define rs (ls|1)

constexpr const int N = 1e5 + 3;
int n;
LL a[N], T[N<<2], tg[N<<2];

void upd(int u)
{ T[u] = T[ls] + T[rs]; }

void pushdown(int u, int L, int R) {
	if(!tg[u])
		return;
	T[ls] += tg[u] * (M-L+1);
	tg[ls] += tg[u];
	T[rs] += tg[u] * (R-M);
	tg[rs] += tg[u];
	tg[u] = 0;
}

void buildTree(int u = 1, int L = 1, int R = n) {
	if(L == R) {
		T[u] = a[L];
		return;
	}
	buildTree(ls, L, M);
	buildTree(rs, M+1, R);
	upd(u);
}

void mdf(int qL, int qR, LL w, int u = 1, int L = 1, int R = n) {
	if(qL <= L && R <= qR) {
		T[u] += w * (R-L+1);
		tg[u] += w;
		return;
	}
	pushdown(u, L, R);
	if(qL <= M)
		mdf(qL, qR, w, ls, L, M);
	if(qR > M)
		mdf(qL, qR, w, rs, M+1, R);
	upd(u);
}

LL qry(int qL, int qR, int u = 1, int L = 1, int R = n) {
	if(qL <= L && R <= qR)
		return T[u];
	pushdown(u, L, R);
	LL res = 0;
	if(qL <= M)
		res += qry(qL, qR, ls, L, M);
	if(qR > M)
		res += qry(qL, qR, rs, M+1, R);
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i)
		a[i] = i;
	buildTree();
	for(int op, x, y; _q--; ) {
		cin >> op >> x >> y;
		if(op == 1) {
			LL k; cin >> k;
			mdf(x, y, k);
		} else
			cout << qry(x, y) << '\n';
	}
	cout.flush(); return 0;
}
