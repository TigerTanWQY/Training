#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string S;
	cin >> S;
	int n = S.size();
	const int INF = 1e9;
	vector<vector<int>> dp(n + 1, vector<int>(2, INF));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int s = 0; s < 2; ++s) {
			if (dp[i][s] == INF) continue;
			char c = S[i];
			char req = (s == 0) ? 'i' : 'o';
			if (c == req) {
				int new_i = i + 1;
				int new_s = s ^ 1;
				dp[new_i][new_s] = min(dp[new_i][new_s], dp[i][s]);
			} else {
				int new_s = s ^ 1;
				int insert_count = dp[i][s] + 1;
				char new_req = (new_s == 0) ? 'i' : 'o';
				if (c == new_req) {
					int new_i = i + 1;
					int new_new_s = new_s ^ 1;
					dp[new_i][new_new_s] = min(dp[new_i][new_new_s], insert_count);
				} else
					if (dp[i][new_s] > insert_count)
						dp[i][new_s] = insert_count;
			}
		}
	int ans = INF;
	for (int s = 0; s < 2; ++s) {
		int k = (s == 1) ? 1 : 0;
		if (dp[n][s] != INF)
			ans = min(ans, dp[n][s] + k);
	}
	cout << ans << endl;
	return 0;
}
