#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cout << (i <= m? "OK": "Too Many Requests") << '\n';
	cout.flush(); return 0;
}
