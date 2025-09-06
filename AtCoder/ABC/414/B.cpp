#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	string ans;
	for(int i = 1, l; i <= n; ++i) {
		char ch;
		cin >> ch >> l;
		if(ans.size() + l > 100) {
			cout << "Too Long" << endl;
			return 0;
		} else
			ans += string(l, ch);
	}
	cout << ans << endl;
	return 0;
}
