#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr const int N = 103, M = 67;
int f[103][67];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i = 1; i < N; ++i)
		for(int j = 1; j < M; ++j)
			f[i][j] = f[i-1][j-1] + 1 + f[i][j-1];
	for(int x, y; cin >> x >> y && (x || y); cout.put('\n')) {
		bool flg = false;
		for(int i = 0; i < M; ++i)
			if(f[x][i] >= y) {
				cout << i;
				flg = true;
				break;
			}
		if(!flg)
			cout << "More than 63 trials needed.";
	}
	cout.flush(); return 0;
}
