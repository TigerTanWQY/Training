#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int MAX_N = 10000000;
long long fac[MAX_N + 3];

void pre() {
	fac[0] = 1;
	for (int i = 1; i <= MAX_N; i++)
		fac[i] = fac[i-1] * i % mod;
}

int calc(long long m, int n) {
	if (m == 0) return 0;
	int cnt = 0;
	for (int i = 1; (long long)i * i <= m; i++)
		if (m % i == 0) {
			if (i <= n) cnt++;
			long long j = m / i;
			if (j != i && j <= n)
				cnt++;
		}
	return cnt;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	pre();
	int T;
	cin >> T;
	while (T--) {
		long long n, m, k;
		cin >> n >> m >> k;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		if (m == 0) {
			long long ans = k % mod * fac[n] % mod;
			if (ans < 0) ans += mod;
			cout << ans << '\n';
		} else {
			int A = calc(m, n);
			long long B = n - A;
			long long s = static_cast<long long>(n) * (n + 1) / 2;
			long long part1 = (k % mod) * (A % mod) % mod;
			part1 = part1 * (n - 1) % mod;
			long long temp = s - k;
			temp %= mod;
			if (temp < 0) temp += mod;
			long long part2 = temp * (B % mod) % mod;
			long long inner = (part1 + part2) % mod;
			inner = (inner % mod + mod) % mod;
			long long ans = inner * fac[n - 2] % mod;
			if (ans < 0) ans += mod;
			cout << ans << '\n';
		}
	}
	cout.flush(); return 0;
}
