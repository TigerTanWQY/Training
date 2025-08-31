#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e6 + 3;
int a[N];
LL s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		s[0] = 0;
		for(int i = 1; i <= n; ++i)
			s[i] = s[i - 1] + a[i - 1];
		LL res = 0x3f3f3f3f3f3f3f3f;
		for(int i = 0; i + n / 2 < n; ++i)
			res = min(res, s[i + n / 2 + 1] - s[i]);
		cout << res << ' ' << s[n] - res;
	}
	cout.flush();
	return 0;
}
