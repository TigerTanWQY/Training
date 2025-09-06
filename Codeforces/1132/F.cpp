#include <bits/stdc++.h>
using namespace std;

char s[505];
int dp[1001][1001];

int main () {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int len = 0; len < n; len++)
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len;
			int Min = 0x3f3f3f3f;
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			for (int k = i; k < j; k++) {
				if (s[j] == s[k]) Min = min(Min, dp[i][k] + dp[k + 1][j - 1]);
				else Min = min(Min, dp[i][k] + dp[k + 1][j - 1] + 1);
			}
			dp[i][j] = Min;
		}
	printf("%d", dp[0][n - 1]);
	return 0;
}
