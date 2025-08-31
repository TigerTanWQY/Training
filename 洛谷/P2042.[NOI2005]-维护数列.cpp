#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
struct fhq_Treap {
	int L, R, sz, w, w_cov;
	bool tag, flg_cov;
	int tot, mxqz, mxhz, mxzd;
} T[N];
stack<int> stk;
int a[N], rt;

int newNode(int v) {
	int id = stk.top(); stk.pop();
	T[id].L = T[id].R = T[id].w_cov = 0;
	T[id].tag = false;
	T[id].sz = 1;
	T[id].w = T[id].tot = v;
	T[id].mxqz = T[id].mxhz = max(0, v);
	T[id].mxzd = v;
	return id;
}

void pushup(int x) {
	if(!x)
		return;
	T[x].sz = T[T[x].L].sz + T[T[x].R].sz + 1;
	T[x].tot = T[T[x].L].tot + T[T[x].R].tot + T[x].w;
	T[x].mxqz = max({T[T[x].L].mxqz, T[T[x].L].tot + T[x].w + T[T[x].R].mxqz, 0});
	T[x].mxhz = max({T[T[x].R].mxhz, T[T[x].L].tot + T[x].w + T[T[x].R].mxhz, 0});
	T[x].mxzd = max(T[x].w, T[x].w + T[T[x].L].mxhz + T[T[x].R].mxqz);
	if(T[x].L)
		T[x].mxzd = max(T[x].mxzd, T[T[x].L].mxzd);
	if(T[x].R)
		T[x].mxzd = max(T[x].mxzd, T[T[x].R].mxzd);
}

void rvs(int x) {
	if(!x)
		return;
	swap(T[x].L, T[x].R);
	swap(T[x].mxhz, T[x].mxqz);
	T[x].tag ^= 1;
}

void cvr(int x, int w) {
	T[x].w = T[x].w_cov = w;
	T[x].tot = T[x].sz * w;
	T[x].mxqz = T[x].mxhz = max(0, T[x].tot);
	T[x].mxzd = max(w, T[x].tot);
	T[x].flg_cov = true;
}

void pushdown(int x) {
	if(!x)
		return;
	if(T[x].tag) {
		if(T[x].L)
			rvs(T[x].L);
		if(T[x].R)
			rvs(T[x].R);
		T[x].tag = false;
	}
	if(T[x].flg_cov) {
		if(T[x].L)
			cvr(T[x].L, T[x].w_cov);
		if(T[x].R)
			cvr(T[x].R, T[x].w_cov);
		T[x].w_cov = T[x].flg_cov = false;
	}
}

void rmv(int x) {
	if(!x)
		return;
	stk.push(x);
	if(T[x].L)
		rmv(T[x].L);
	if(T[x].R)
		rmv(T[x].R);
}

void split(int x, int& L, int& R, int k) {
	if(x)
		pushdown(x);
	if(!x) {
		L = R = 0;
		return;
	}
	if(T[T[x].L].sz < k) {
		L = x;
		split(T[x].R, T[L].R, R, k - T[T[x].L].sz - 1);
	} else {
		R = x;
		split(T[x].L, L, T[R].L, k);
	}
	pushup(x);
}

void mrge(int x, int y, int& M) {
	if(!x || !y) {
		M = x + y;
		return;
	}
	if(90000008 % (T[x].sz + T[y].sz) < T[x].sz) {
		pushdown(x);
		M = x;
		mrge(T[x].R, y, T[M].R);
		pushup(x);
	} else {
		pushdown(y);
		M = y;
		mrge(x, T[y].L, T[M].L);
		pushup(y);
	}
}

int build(int L, int R) {
	if(L == R)
		return newNode(a[L]);
	int x, M = (L + R) >> 1;
	mrge(build(L, M), build(M + 1, R), x);
	return x;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i = 1; i <= N - 3; ++i)
		stk.push(i);
	int n, _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	mrge(rt, build(1, n), rt);
	for(string op; _q--; ) {
		cin >> op;
		if(op == "INSERT") {
			int pos, tot, x, y;
			cin >> pos >> tot;
			split(rt, x, y, pos);
			for(int i = 1; i <= tot; ++i)
				cin >> a[i];
			mrge(x, build(1, tot), x);
			mrge(x, y, rt);
		} else if(op == "DELETE") {
			int pos, tot, x, y, z;
			cin >> pos >> tot;
			split(rt, x, y, pos - 1);
			split(y, y, z, tot);
			rmv(y);
			mrge(x, z, rt);
		} else if(op == "MAKE-SAME") {
			int pos, tot, w, x, y, z;
			cin >> pos >> tot >> w;
			split(rt, x, y, pos - 1);
			split(y, y, z, tot);
			cvr(y, w);
			mrge(x, y, x);
			mrge(x, z, rt);
		} else if(op == "REVERSE") {
			int pos, tot, x, y, z;
			cin >> pos >> tot;
			split(rt, x, y, pos - 1);
			split(y, y, z, tot);
			rvs(y);
			mrge(x, y, y);
			mrge(y, z, rt);
		} else if(op == "GET-SUM") {
			int pos, tot, x, y, z;
			cin >> pos >> tot;
			split(rt, x, y, pos - 1);
			split(y, y, z, tot);
			cout << T[y].tot << '\n';
			mrge(x, y, y);
			mrge(y, z, rt);
		} else if(op == "MAX-SUM")
			cout << T[rt].mxzd << '\n';
	}
	cout.flush(); return 0;
}
