#include <bits/stdc++.h>
using namespace std;

int a[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, X;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> X;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(X <= a[i])
			++ans;
	cout << ans << endl;
	return 0;
}
