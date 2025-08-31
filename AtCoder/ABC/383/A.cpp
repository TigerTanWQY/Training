#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	int tot = 0;
	for(int t = 0, i = 1; i <= n; ++t) {
		if(t == a[i].first) {
			tot += a[i].second;
			++i;
		}
		if(tot > 0)
			--tot;
	}
	cout << tot + 1 << endl;
	return 0;
}
