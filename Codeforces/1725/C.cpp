#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 35, MOD = 998244353;
int n, m;
ll asum, ans;
int d[MAXN];
bool isD[MAXN];
int cnt;

ll qpow(ll a, int b) {
	ll ans = 1;
	for(; b; b >>= 1) {
		if(b & 1)ans = ans * a % MOD;
		a = a * a % MOD;
	}
	return ans;
}

ll inv[MAXN], finv[MAXN], fac[MAXN];

void init(int x) {
	inv[1] = finv[0] = finv[1] = fac[0] = fac[1] = 1;
	for(int i = 2; i <= x; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll A(int n, int m) {
	if(n < m)return 0;
	return fac[n] * finv[n - m] % MOD;
}

ll C(int n, int m) {
	if(n < m)return 0;
	return A(n, m) * finv[m] % MOD;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> d[i];
		asum += d[i];
	}
	if(asum % 2 == 0){
		ll nsum = 0;
		for(int i = 1, r = 1; i <= n; i++) {
			if(isD[i])continue;
			while(nsum < asum / 2) {
				nsum += d[r];
				r++;
				if(r > n)r = 1;
			}
			if(isD[r])continue;
			if(nsum == asum / 2) {
				cnt++;
				isD[i] = isD[r] = 1;
			}
			nsum -= d[i];
		}
	}
	init(m + 2);
	for(int i = 0; i <= cnt; i++)
		ans = (ans + C(cnt, i) * A(m, i) % MOD * qpow(A(m - i, 2) % MOD, cnt - i) % MOD * qpow(m - i, n - 2 * cnt) % MOD) % MOD;
	cout << ans << endl;
	return 0;
}
