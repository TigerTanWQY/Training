#include <bits/stdc++.h>
#define Lu (u << 1)
#define Ru (u << 1 | 1)
using namespace std;
using LL = long long;

constexpr const int N = 5e4 + 3;
int w[N << 2], T[N << 2], a[N][60], phi[N], idx = 0;
int n, m, P, c;

int ph(int x) {
	int res = x;
	for(int i = 2; (LL)i * i <= x; ++i)
		if(x % i == 0) {
			for(; x % i == 0; x /= i);
			res /= i; res *= i - 1;
		}
	if(x > 1)
	{ res /= x; res *= x - 1; }
	return res;
}

int Mod(LL x, int mod)
{ return x >= mod? x % mod + mod: x; }

int qpow(int x, int y, int mod) {
	int res = 1;
	for(; y; x = Mod((LL)x * x, mod), y >>= 1)
		if(y & 1)
			res = Mod((LL)res * x, mod);
	return res;
}

int calc(int x, int k, int id) {
	if(phi[id] == 1)
		return c? 1: 0;
	else if(id == k - 1)
		return qpow(c, x, phi[id]);
	else
		return qpow(c, calc(x, k, id + 1), phi[id]);
}

void update(int u) {
	T[u] = T[Lu] + T[Ru];
	if(T[u] >= P)
		T[u] -= P;
	w[u] = min(w[Lu], w[Ru]);
}

void build(int u, int L, int R) {
	if(L == R) {
		T[u] = a[L][0];
		if(T[u] >= P)
			T[u] -= P;
		return;
	}
	int M = (L + R) >> 1;
	build(Lu, L, M);
	build(Ru, M + 1, R);
	update(u);
}

void chg(int u, int L, int R, int x, int y) {
	if(w[u] >= idx + 1)
		return;
	if(L == R) {
		++w[u];
		T[u] = a[L][min(w[u], idx + 1)];
		if(T[u] >= P)
			T[u] -= P;
		return;
	}
	int M = (L + R) >> 1;
	if(x <= M)
		chg(Lu, L, M, x, y);
	if(y > M)
		chg(Ru, M + 1, R, x, y);
	update(u);
}

int ask(int u, int L, int R, int x, int y) {
	if(x <= L && R <= y)
		return T[u];
	int M = (L + R) >> 1, res = 0;
	if(x <= M)
		res = ask(Lu, L, M, x, y);
	if(y > M)
		res += ask(Ru, M + 1, R, x, y);
	return res >= P? res - P: res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> P >> c;
	for(phi[0] = P; phi[idx] > 1; ++idx)
		phi[idx + 1] = ph(phi[idx]);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i][0];
		for(int j = 1; j <= idx + 1; ++j)
			a[i][j] = calc(a[i][0], j, 0);
	}
	build(1, 1, n);
	for(int op, L, R; m--; ) {
		cin >> op >> L >> R;
		if(op)
			cout << ask(1, 1, n, L, R) << '\n';
		else
			chg(1, 1, n, L, R);
	}
	cout.flush();
	return 0;
}
