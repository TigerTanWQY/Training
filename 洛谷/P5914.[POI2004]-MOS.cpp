#include <bits/stdc++.h>
using namespace std;

int t[100003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> t[i];
	if(n == 1) {
		cout << t[1] << endl;
		return 0;
	}
	sort(t + 1, t + n + 1);
	long long ans = 0;
	for(; n > 3; n -= 2)
		ans += min(t[1] * 2 + t[n - 1], t[1] + t[2] * 2) + t[n];
	if(n == 2)
		ans += t[2];
	else if(n == 3)
		ans += t[1] + t[2] + t[3];
	cout << ans << endl;
	return 0;
}
