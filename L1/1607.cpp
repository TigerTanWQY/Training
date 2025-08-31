#include <bits/stdc++.h>
using namespace std;

register constexpr const auto N = 1003;
int a[N][N];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> m >> n;
	for(register auto i = 1; i <= m; ++i)
		for(register auto j = 1; j <= n; ++j)
			cin >> a[i][j];
	for(register auto i = 1; i <= n; ++i)
	{
		for(register auto j = 1; j <= m; ++j)
			cout << a[j][i] << ' ';
		cout<< '\n';
	}
	return 0;
}