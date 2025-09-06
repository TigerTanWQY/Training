#include <iostream>
#include <bitset>
using namespace std;
using LL = long long;

constexpr const int N = 5e4, NN = N + 3;
bitset<NN> b;
int mu[NN], p[NN];
LL s[NN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	b.reset(); mu[1] = 1; int cnt = 0;
	for(int i = 2; i <= N; ++i) {
		if(!b[i])
		{ p[++cnt] = i; mu[i] = -1; }
		for(int j = 1; j <= cnt && i * p[j] <= N; ++j) {
			b[i * p[j]] = true;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			} else
				mu[i * p[j]] = -mu[i];
		}
	}
	for(int i = 1; i <= N; ++i)
		mu[i] += mu[i - 1];
	for(int x = 1; x <= N; ++x) {
		LL res = 0;
		for(int i = 1, j; i <= x; i = j + 1)
		{ j = x / (x / i); res += (LL) (j - i + 1) * (x / i); }
		s[x] = res;
	}
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
		if(n > m)
			swap(n, m);
		LL ans = 0;
		for(int i = 1, j; i <= n; i = j + 1) {
			j = min(n / (n / i), m / (m / i));
			ans += (mu[j] - mu[i - 1]) * s[n / i] * s[m / i];
		}
		cout << ans;
	}
	cout.flush();
	return 0;
}
