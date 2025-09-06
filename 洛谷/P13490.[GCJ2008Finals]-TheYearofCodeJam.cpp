#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 53;
int a[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int _ = 1, n, m; _ <= _T; cout.put('\n'), ++_) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> a[i][j];
		cout << "Case #" << _ << ": ";
	}
	cout << endl;
	return 0;
}
