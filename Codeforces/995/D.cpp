#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		LL x, y;
		cin >> n >> x >> y;
		LL tot = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			tot += a[i];
		}
		LL ans = 0;
		for(int i = 1; i < n; ++i)
			for(int j = i + 1; j <= n; ++j)
				if(a[i] + a[j] <= tot - x &&
					a[i] + a[j] >= tot - y)
					++ans;
		cout << ans;
	}
	cout.flush();
	return 0;
}
