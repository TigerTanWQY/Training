#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 19940417;

LL sum1(LL L, LL R)
{ return (R - L + 1) * (L + R) / 2 % P; }

LL calc1(LL k) {
	LL ans = k * k % P;
	for(int L = 1, R; L <= k; L = R + 1) {
		R = k / (k / L);
		ans = ((ans - sum1(L, R) * (k / L) % P) % P + P) % P;
	}
	return ans;
}

LL calc2(LL x)
{ return x * (x + 1) % P * (2 * x + 1) % P * 3323403 % P; }

LL sum2(LL L, LL R)
{ return (calc2(R) - calc2(L - 1) + P) % P; }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL n, m;
	cin >> n >> m;
	if(n > m)
		swap(n, m);
	LL ans = ((calc1(n) * calc1(m) % P - n * n % P * m % P) % P + P) % P;
	for(LL L = 1, R; L <= n; L = R + 1) {
		R = min(n / (n / L), m / (m / L));
		ans = (ans + sum1(L, R) * (n / L * m % P + m / L * n % P) % P) % P;
		ans = (ans - sum2(L, R) * (n / L) % P * (m / L) % P + P) % P;
	}
	cout << (ans % P + P) % P << endl;
	return 0;
}
