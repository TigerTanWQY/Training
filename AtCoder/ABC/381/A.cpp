#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	if((n & 1) && s[n / 2] == '/' &&
		s.substr(0, n / 2) == string(n / 2, '1') &&
		s.substr(n / 2 + 1) == string(n / 2, '2'))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}
