#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 23;
string s[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int n, m; cin >> n >> m; cout.put('\n')) {
		for(int i = 1; i <= m; ++i)
			cin >> s[i];
	}
	cout.flush(); return 0;
}
