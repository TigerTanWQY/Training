#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_set<string> st;
	for(int _ = 4; _--; ) {
		string s;
		cin >> s;
		st.insert(s);
	}
	if(st.count("H") && st.count("2B") && st.count("3B") && st.count("HR"))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}
