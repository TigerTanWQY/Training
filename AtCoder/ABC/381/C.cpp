#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	int ans = 1;
	for(int i = s.find('/'); i != string::npos && i < n; i = s.find('/', i + 1)) {
		int k = 1;
		for(; i - k >= 0 && i + k < n && s[i - k] == '1' && s[i + k] == '2'; ++k);
		--k;
		ans = max(ans, k * 2 + 1);
		i += k;
	}
	cout << ans << endl;
	return 0;
}
