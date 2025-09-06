#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans[1505][26];
int s[1505][26];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 26; j++)
			s[i][j] = s[i - 1][j];
		char ch; cin >> ch;
		s[i][ch - 'a']++;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j + i - 1 <= n; j++)
			for (int k = 0; k < 26; k++)
				ans[i - (s[j + i - 1][k] - s[j - 1][k])][k] = i;
	cin >> q;
	while (q--) {
		int a0; char ch;
		cin >> a0 >> ch;
		int x = ans[a0][ch - 'a'];
		cout << (x == 0? n: x) << '\n';
	}
	cout.flush(); return 0;
}
