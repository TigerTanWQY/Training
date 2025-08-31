#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
		cin >> a[i].first;
	for(int i = 0; i < m; ++i)
		cin >> a[i].second;
	sort(a, a + m);
	long long tot = 0, idx = 0;
	for(int i = 0; i < m; ++i) {
		if(tot < a[i].first - 1) {
			cout << "-1" << endl;
			return 0;
		}
		tot += a[i].second;
		idx += (long long)a[i].second * a[i].first;
	}
	if(tot != n) {
		cout << -1 << endl;
		return 0;
	}
	cout << (long long)n * (n + 1) / 2 - idx << endl;
	return 0;
}