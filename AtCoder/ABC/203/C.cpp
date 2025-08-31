#include <bits/stdc++.h>
using namespace std;
using LL = long long;

pair<LL, int> a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	LL k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		if(a[i].first - a[i - 1].first <= k) {
			k -= a[i].first - a[i - 1].first;
			k += a[i].second;
		} else {
			cout << a[i - 1].first + k;
			k = 0;
			break;
		}
	if(k) {
		cout << a[n].first + k;
		k = 0;
	}
	cout << endl;
	return 0;
}
