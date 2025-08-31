#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	bitset<128> b;
	for(const auto& ch: t)
		b[ch] = true;
	for(int i = 1; i < s.size(); ++i)
		if(isupper(s[i]) && !b[s[i - 1]]) {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}
