#include <bits/stdc++.h>
using namespace std;

constexpr const int n = 9;
int a[n + 1][n + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x;
	cin >> x;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i * j != x)
				ans += i * j;
	cout << ans << endl;
	return 0;
}
