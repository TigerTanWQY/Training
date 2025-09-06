#include <bits/stdc++.h>
using namespace std;

mt19937 rd(random_device{}());
constexpr const int N = 3e7 + 3, INF = 2147483647;
int sz[N], Ls[N], Rs[N], val[N], pri[N], a[N], cnt = 0;

void upd(int u, int v) {
	sz[u] = sz[v];
	val[u] = val[v];
	pri[u] = pri[v];
	Ls[u] = Ls[v];
	Rs[u] = Rs[v];
}
void push(int x) {
	if(x)
		sz[x] = sz[Ls[x]] + sz[Rs[x]] + 1;
}
void split(int rt, int k, int &L, int &R) {
	if(!rt) {
		L = R = 0;
		return;
	}
	int trt = ++cnt;
	upd(trt, rt);
	if(k < val[rt]) {
		R = trt;
		split(Ls[rt], k, L, Ls[R]);
		push(R);
	} else {
		L = trt;
		split(Rs[rt], k, Rs[L], R);
		push(L);
	}
}
int mrge(int L, int R) {
	if(!L || !R)
		return L + R;
	int trt = ++cnt;
	if(pri[L] < pri[R]) {
		upd(trt, L);
		Rs[trt] = mrge(Rs[trt], R);
		push(trt);
	} else {
		upd(trt, R);
		Ls[trt] = mrge(L, Ls[trt]);
		push(trt);
	}
	return trt;
}
int rnk(int rt, int v) {
	if(!rt)
		return 0;
	if(v < val[rt])
		return rnk(Ls[rt],v);
	else
		return sz[Ls[rt]] + rnk(Rs[rt],v) + 1;
}
void ist(int &rt, int v) {
	int trt = ++cnt;
	val[cnt] = v;
	pri[cnt] = rd();
	sz[cnt] = 1;
	Ls[cnt] = Rs[cnt] = 0;
	if(!rt) {
		rt = cnt;
		return;
	}
	int L, R;
	split(rt, v, L, R);
	rt = mrge(mrge(L, trt), R);
}
void ers(int &rt, int v) {
	int L, R, M;
	split(rt, v, L, M);
	split(L, v - 1, L, R);
	if(R) {
		int trt = mrge(Ls[R], Rs[R]);
		rt = mrge(L, mrge(trt, M));
	} else
		rt = mrge(L, M);
}
int Kth(int rt, int k) {
	if(k <= sz[Ls[rt]])
		return Kth(Ls[rt], k);
	else if(k == sz[Ls[rt]] + 1)
		return val[rt];
	else
		return Kth(Rs[rt], k - sz[Ls[rt]] - 1);
}
int pre(int rt, int x) {
	if(!rt)
		return -INF;
	if(val[rt] < x)
		return max(val[rt], pre(Rs[rt], x));
	else
		return pre(Ls[rt], x);
}
int nxt(int rt, int x) {
    if(!rt)
		return INF;
    if(val[rt] > x)
		return min(val[rt], nxt(Ls[rt], x));
    else
		return nxt(Rs[rt], x);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
//	a[0] = 0;
	for(int i = 1, v, opt, x; i <= n; ++i) {
		cin >> v >> opt >> x;
		a[i] = a[v];
		if(opt == 1)
			ist(a[i], x);
		else if(opt == 2)
			ers(a[i], x);
		else if(opt == 3)
			cout << rnk(a[i], x - 1) + 1 << '\n';
		else if(opt == 4)
			cout << Kth(a[i], x) << '\n';
		else if(opt == 5)
			cout << pre(a[i], x) << '\n';
		else if(opt == 6)
			cout << nxt(a[i], x) << '\n';
	}
	cout.flush(); return 0;
}
