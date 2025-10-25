#include <bits/stdc++.h>
using namespace std;

int f[24][82];

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	int V1, V2, n;
	cin >> V1 >> V2 >> n;
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for(int v1, v2, w; n--; ) {
		cin >> v1 >> v2 >> w;
		for(int j1 = V1; ~j1; --j1)
			for(int j2 = V2; ~j2; --j2)
				f[j1][j2] = min(f[j1][j2], f[max(j1-v1, 0)][max(j2-v2, 0)] + w);
	}
	cout << f[V1][V2] << endl;
	return 0;
}
