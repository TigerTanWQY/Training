#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(string s; _T--; cout.put('\n')) {
		int n;
		cin >> n >> s;
		const int m = 1 << n;
		vector<bool> dp(m, false);
		dp[0] = true;
		for(int S = 1; S < m; ++S)
			for(int j = 0; j < n; ++j)
				if(S >> j & 1) {
					int prv = S ^ (1 << j);
					if(dp[prv] && s[S - 1] == '0') {
						dp[S] = true;
						break;
					}
				}
		cout << (dp[m - 1]? "Yes": "No");
	}
	cout.flush(); return 0;
}
