#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
pair<LL, int> a[N];
LL ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	LL k;
	cin >> n >> m >> k;
	LL tot = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
		tot += a[i].first;
	}
	k -= tot;
	sort(a + 1, a + n + 1, greater<>());
	for(int i = 1; i <= n; ++i) {
		LL L = 0, R = k + 1;
		while(L + 1 < R) {
			LL M = (L + R) >> 1;
			if(a[i].first + M >= a[m].first + k - M)
				R = M;
			else
				L = M;
		}
		if(R > k)
			ans[a[i].second] = -1;
		else
			ans[a[i].second] = R;
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}