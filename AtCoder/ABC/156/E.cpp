#include <iostream>
#include <algorithm>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

mint fac[200'003];

inline mint C(const int n, const int m)
{ return fac[n] * fac[m].inv() * fac[n - m].inv(); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fac[0] = 1;
	for(int i = 1; i <= 200'000; ++i)
		fac[i] = fac[i - 1] * i;
	int n, k;
	cin >> n >> k;
	mint ans = 0;
	for(int i = 0; i <= min(n - 1, k); ++i)
		ans += C(n, i) * C(n - 1, n - i - 1);
	cout << ans.val();
	cout.flush();
	return 0;
}