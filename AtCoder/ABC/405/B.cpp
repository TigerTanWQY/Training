#include <bits/stdc++.h>
using namespace std;

int a[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> cnt;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] <= m)
			++cnt[a[i]];
	}
	if(cnt.size() != m) {
		cout.put('0') << endl;
		return 0;
	}
	for(int i = n; i; --i) {
		if(a[i] > m)
			continue;
		--cnt[a[i]];
		if(cnt[a[i]] == 0)
			cnt.erase(a[i]);
		if(cnt.size() != m) {
			cout << n - i + 1;
			break;
		}
	}
	cout << endl;
	return 0;
}
