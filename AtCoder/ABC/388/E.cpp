#include <bits/stdc++.h>
using namespace std;

int a[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0, L = 0, R = 0;
	for(; R < n && a[R] < 2 * a[L]; ++R);
	for(; L < n && R < n; )
		if(a[R] >= 2 * a[L]) {
			++ans; ++L; ++R;
			for(; R < n && a[R] < 2 * a[L]; ++R);
		} else
			++L;
	cout << ans << endl;
	return 0;
}
