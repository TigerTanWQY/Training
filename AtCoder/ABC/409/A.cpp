#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s, t;
	cin >> n >> s >> t;
	for(int i = 0; i < n; ++i)
		if(s[i] == 'o' && t[i] == 'o') {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}
