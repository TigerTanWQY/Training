#include <bits/stdc++.h>
using namespace std;

pair<int, string> a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i].second >> a[i].first;
	sort(a, a + n, greater<>());
	cout << a[1].second << endl;
	return 0;
}
