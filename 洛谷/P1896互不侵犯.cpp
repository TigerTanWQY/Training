#include <bits/stdc++.h>
using namespace std;

bool b[515];
int v[515];
long long f[12][515][84]{{{1}}};

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(register auto i = 0; i < 1 << n; ++i)
	{
		for(register auto j = i; j != 0; j &= j - 1)
			++v[i];
		b[i] = (i & (i << 1)) == 0;
	}
	for(register auto i = 1; i <= n; ++i)
		for(register auto j = 0; j < 1 << n; ++j)
			for(register auto k = 0; k <= n * n; ++k)
				if(f[i - 1][j][k] != 0)
					for(register auto l = 0; l < 1 << n; ++l)
						if((l & j) == 0 && ((l << 1) & j) == 0 && ((l >> 1) & j) == 0 && b[l])
							f[i][l][k + v[l]] += f[i - 1][j][k];
	register auto ans = 0LL;
	for(register auto i = 0; i < 1 << n; ++i)
		ans += f[n][i][m];
	cout << ans;
	return 0;
}