#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int n = 4;
	for(int i = 0; i < n; ++i)
		cin >> a[i].first;
	for(int i = 0; i < n; ++i)
		cin >> a[i].second;
	int ans = 0;
	for(int i = 0; i + 1 < n; ++i)
		for(int j = i + 1; j < n; ++j)
			if((a[i].first > a[j].first && a[i].second < a[j].second) || (a[i].first < a[j].first && a[i].second > a[j].second))
				++ans;
	cout << ans << endl;
	return 0;
}
