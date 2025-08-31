#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 5'003;
int d[N], md[N];
LL sd[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k, _q;
	cin >> k >> _q;
	for(int i = 0; i < k; ++i) //!
		cin >> d[i];
	for(int n, x, m; _q--; cout.put('\n')) {
		cin >> n >> x >> m;
		LL ans = --n;
		for(int i = 1; i <= k; ++i) {
			md[i] = d[i] % m;
			sd[i] = sd[i - 1] + md[i];
		}
		LL tot = x + n / k * sd[k] + sd[n % k];
		int cnt = count_if(md + 1, md + k + 1, [&](const int& i){ return !i; });
		ans -= (LL)n / k * cnt + count_if(md + 1, md + n % k + 1, [&](const int& i){ return !i; }) + tot / m - x / m;
		cout << ans;
	}
	cout.flush();
	return 0;
}