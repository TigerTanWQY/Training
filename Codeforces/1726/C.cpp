#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		int ans = 0; char c1 = '(', c2;
		for(int i = 0; i < n * 2; c1 = c2, ++i) {
			for(; cin >> c2 && (c2 ^ '(') && (c2 ^ ')'); );
			if(c1 == '(' && c2 == '(')
				++ans;
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
