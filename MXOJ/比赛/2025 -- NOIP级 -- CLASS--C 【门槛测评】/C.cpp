#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 998244353, N = 1e5 + 3;
int a[N][23], id[N];

long long fac(int n) {
	long long res = 1;
	for(int i = 1; i <= n; ++i)
		res *= i;
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			char ch;
			cin >> ch;
			a[i][j] = ch - '0';
		}
	iota(id + 1, id + n + 1, 1);
	do {
		;
	} while(next_permutation(id + 1, id + n + 1));
	for(int i = 1; i <= m; ++i)
		cout << fac(n) << '\n';
	cout << endl;
	return 0;
}
