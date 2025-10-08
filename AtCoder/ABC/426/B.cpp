#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	sort(begin(s), end(s));
	if(s[0] != s[1])
		cout.put(s[0]);
	else
		cout.put(s.back());
	cout << endl; return 0;
}
