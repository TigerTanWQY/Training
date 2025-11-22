#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int d[N];
LL A[N], a[N], p[11];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	LL m;
	cin >> n >> m;
	unordered_map<LL, int> mp;
	for(int i = 0; i < n; ++i) {
		cin >> A[i];
		a[i] = A[i] % m;
		d[i] = to_string(A[i]).size();
		++mp[a[i]];
	}
	p[0] = 1;
	for(int i = 1; i <= 10; ++i)
		p[i] = p[i-1] * 10 % m;
	unordered_map<LL, int> C[11];
	for(int k = 1; k <= 10; ++k)
		for(const auto& [x, y]: mp)
			C[k][(x * p[k]) % m] += y;
	LL ans = 0;
	for(int j = 0; j < n; ++j)
		ans += C[d[j]][(m - a[j]) % m];
	cout << ans << endl;
	return 0;
}
