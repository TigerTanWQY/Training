#include <bits/stdc++.h>
using namespace std;

int v1[103], v2[103], f[1003][503];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int V1, V2, n;
	cin >> V1 >> V2 >> n;
	for(int i = 1; i <= n; ++i)
		cin >> v1[i] >> v2[i];
	for(int i = 1; i <= n; ++i)
		for(int j = V1; j >= v1[i]; --j)
			for(int k = V2-1; k >= v2[i]; --k)
				f[j][k] = max(f[j][k], f[j-v1[i]][k-v2[i]] + 1);
	int res = V2;
	for(int i = 0; i < V2; ++i)
		if(f[V1][i] == f[V1][V2-1]) {
			res = i;
			break;
		}
	cout << f[V1][V2-1] << ' ' << V2 - res << endl;
	return 0;
}
