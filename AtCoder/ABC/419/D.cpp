#include <bits/stdc++.h>
using namespace std;

bool b[500003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; string s, t;
	cin >> n >> m >> s >> t;
	for(int L, R; m--; ) {
		cin >> L >> R;
		b[L] ^= true;
		if(R <= n)
			b[R + 1] ^= true;
	}
	string ans;
	bool flg = 0;
	for(int i = 0; i < n; ++i) {
		flg ^= b[i + 1];
		ans += (flg? t[i]: s[i]);
	}
	cout << ans << endl;
	return 0;
}
