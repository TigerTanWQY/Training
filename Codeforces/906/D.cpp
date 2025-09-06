#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

__gnu_pbds::gp_hash_table<int, int> phi;
int w[100003];

int f(int x) {
	int res = x;
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0)
			res -= res / i;
		for(; x % i == 0; x /= i);
	}
	if(x > 1)
		res -= res / x;
	return res;
}

long long qpow(long long a, int b, int p) {
	long long res = 1;
	bool flag = false;
	for(; b; b >>= 1) {
		if(b & 1) {
			res *= a;
			if(res >= p)
				flag = true;
			res %= p;
		}
		a *= a;
		if(a >= p)
			flag = true;
		a %= p;
	}
	if(flag)
		res += p;
	return res;
}

int dfs(int L, int R, int p) {
	if(L == R + 1 || p == 1)
		return 1;
	return qpow(w[L], dfs(L + 1, R, phi[p]), p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, p, _q;
	cin >> n >> p;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	int nw = p;
	for(; nw != 1; nw = phi[nw])
		phi[nw] = f(nw);
	phi[nw] = 1;
	cin >> _q;
	for(int L, R; _q--; cout.put('\n')) {
		cin >> L >> R;
		cout << dfs(L, R, p) % p;
	}
	cout.flush();
	return 0;
}
