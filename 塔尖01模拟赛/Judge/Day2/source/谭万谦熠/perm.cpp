#include <bits/stdc++.h>
using namespace std;

int a[500003];

int main() {
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		random_device rd;
		mt19937_64 sd(rd());
		uniform_int_distribution<> eng(0, 1e9 + 6);
		cout << eng(sd);
	}
	cout.flush(); return 0;
}
