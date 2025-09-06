#include <bits/stdc++.h>
using namespace std;

int a[103], b[103], ans[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{ cin >> a[i]; b[i] = a[i]; }
	sort(b + 1, b + n + 1, greater<>());
	for(int i = 1; i <= n; ++i)
		if(!ans[b[i]])
			ans[b[i]] = i;
	for(int i = 1; i <= n; ++i)
		cout << ans[a[i]] << '\n';
	cout.flush(); return 0;
}
