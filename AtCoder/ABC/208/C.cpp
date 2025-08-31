#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
pair<int, int> a[N];
long long f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		f[a[i].second] = k / n + (i <= k % n);
	for(int i = 1; i <= n; ++i)
		cout << f[i] << '\n';
	cout.flush();
	return 0;
}
