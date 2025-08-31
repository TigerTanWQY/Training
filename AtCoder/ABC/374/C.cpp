#include <bits/stdc++.h>
using namespace std;

int a[23];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0x3f3f3f3f;
	for(int s = 0; s < 1 << n; ++s) {
		int tot1 = 0, tot2 = 0;
		for(int i = 0; i < n; ++i)
			if(s & 1 << i)
				tot1 += a[i];
			else
				tot2 += a[i];
		ans = min(ans, max(tot1, tot2));
	}
	cout << ans << endl;
	return 0;
}
