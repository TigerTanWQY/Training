#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(string s; _T--; cout.put('\n')) {
		int n;
		cin >> n >> s;
		if(n == 1) {
			cout << s;
			continue;
		}
		int l0 = -1;
		for(int l = 0; l < n - 1; ++l)
			if(s[l + 1] < s[l]) {
				l0 = l;
				break;
			}
		if(l0 == -1)
			cout << s;
		else {
			int j0 = n;
			for(int j = l0 + 1; j < n; ++j)
				if(s[j] > s[l0]) {
					j0 = j;
					break;
				}
			string ans = s.substr(0, l0) + s.substr(l0+1, j0 - l0 - 1) + s[l0];
			if(j0 < n)
				ans += s.substr(j0);
			cout << ans;
		}
	}
	cout.flush(); return 0;
}
