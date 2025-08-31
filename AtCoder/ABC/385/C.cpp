#include <bits/stdc++.h>
using namespace std;

int a[3003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 1;
	for(int i = 0; i < n; ++i)
		for(int k = 1; k <= (n - i) / 2; ++k) {
			int cnt = 1;
			for(int j = i + k; j < n; j += k)
				if(a[j] == a[i])
					++cnt;
				else
					break;
			ans = max(ans, cnt);
		}
	cout << ans << endl;
	return 0;
}
