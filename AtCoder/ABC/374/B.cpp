#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s, t;
	cin >> s >> t;
	if(s == t) {
		cout.put('0'); cout << endl;
		return 0;
	}
	for(int i = 0; i < s.size() && i < t.size(); ++i)
		if(s[i] != t[i]) {
			cout << i + 1 << endl;
			return 0;
		}
	cout << min(s.size(), t.size()) + 1 << endl;
	return 0;
}
