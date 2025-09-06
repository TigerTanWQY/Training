#include <bits/stdc++.h>
using namespace std;

int f[203][9];

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		f[i][1] = f[i][0] = 1;
	for(int i = 2; i <= n; ++i)
		for(int x = 2; x <= k; ++x)
			if(i > x)
				f[i][x] = f[i - 1][x - 1] + f[i - x][x];
			else
				f[i][x] = f[i - 1][x - 1];
	cout << f[n][k] << endl;
	return 0;
}
