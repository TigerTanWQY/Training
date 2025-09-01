#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(string s, t; _T--; cout.put('\n')) {
		int n;
		cin >> n >> s >> t;
		for(int i = 0; i < n; ++i)
			if(s[i] != t[i])
				break;
	}
	cout.flush(); return 0;
}
