#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, fst, lst; _T--;cout.put('\n')) {
		cin >> n >> fst;
		for(int _ = 2, x; _ < n && cin >> x; ++_);
		cin >> lst;
		cout << (fst < lst? "YES": "NO");
	}
	cout.put('\n'); return 0;
}
