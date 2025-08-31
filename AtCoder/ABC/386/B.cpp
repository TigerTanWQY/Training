#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	const int n = s.size();
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		++ans;
		if(i + 1 < n && s[i] == '0' && s[i + 1] == '0')
			++i;
	}
	cout << ans << endl;
	return 0;
}
