#include <bits/stdc++.h>
using namespace std;

int S[8],C[8];
double f[5000][1 << 8], P[8];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, V;
	cin >> n >> V;
	for(int i = 0; i < n; ++i)
	{ cin >> S[i] >> C[i] >> P[i]; P[i] /= 100; }
	for(int i = V; ~i; --i)
		for(int j = 0; j < 1 << n; ++j)
			for(int k = 0; k < n; ++k)
				if(!(j >> k & 1) && C[k] <= V - i)
					f[i][j] = max(f[i][j], P[k] * (S[k] + f[i + C[k]][j | 1 << k]) +
									(1 - P[k]) * f[i + C[k]][j]);
	cout << fixed << setprecision(8) << f[0][0] << endl;
	return 0;
}
