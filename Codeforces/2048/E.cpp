#include<bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
long long ans[N << 1][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; ) {
		cin >> n >> m;
		if(2 * n <= m)
			cout << "NO\n";
		else {
			cout << "YES\n";
			for(int i = 1; i <= m; ++i) {
				int k = i;
				for(int j = 1; j <= n; ++j) {
					ans[k][i] = ans[k + 1][i] = j;
					if(k == 2 * n)
						ans[1][i] = j;
					k += 2;
					if(k > 2 * n)
						k -= 2 * n;
				}
			}
			for(int i = 1; i <= 2 * n; ++i) {
				for(int j = 1; j <= m; ++j)
					cout << ans[i][j] << ' ';
				cout.put('\n');
			}
		}
	}
	return 0;
}
