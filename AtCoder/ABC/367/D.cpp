#include <iostream>
using namespace std;

constexpr const int N = 2 * 200'003, M = 1'000'003;
int a[N], s[N], mp[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; ++i) {
		s[i] = (s[i - 1] + a[i]) % m;
		if(i <= n)
			++mp[s[i]];
	}
	long long ans = 0;
	for(int i = n + 1; i <= 2 * n; ++i) {
		--mp[s[i - n]];
		ans += mp[s[i]];
		++mp[s[i]];
	}
	cout << ans;
	cout.flush();
	return 0;
}