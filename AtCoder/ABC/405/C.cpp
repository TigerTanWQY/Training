#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
int a[N];
long long s[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += a[i] * (s[n] - s[i]);
	cout << ans << endl;
	return 0;
}
