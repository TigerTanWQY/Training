#include <bits/stdc++.h>
using namespace std;

string getmin(string s) {
	int n = s.size();
	s += s;
	int i = 0, j = 1;
	while(j < n) {
		int k = 0;
		for(; k + 1 < n && s[i + k] == s[j + k]; ++k);
		(s[i + k] > s[j + k]? i: j) += k + 1;
		if(i == j)
			++j;
		if(i > j)
			swap(i, j);
	}
	return s.substr(i, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n; cin >> n; cout.put('\n')) {
		unordered_set<string> st;
		for(string s; n--; ) {
			cin >> s;
			st.insert(getmin(s));
		}
		cout << st.size();
	}
	cout.flush();
	return 0;
}
