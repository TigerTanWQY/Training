#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	if(s.size() & 1) {
		cout << "No" << endl;
		return 0;
	}
	unordered_set<char> st;
	for(int i = 1; i < s.size(); i += 2)
		if(s[i] != s[i - 1] || st.count(s[i])) {
			cout << "No" << endl;
			return 0;
		} else
			st.insert(s[i]);
	cout << "Yes" << endl;
	return 0;
}
