#include <bits/stdc++.h>
using namespace std;

bool h[2003], l[2003];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(register auto i = 1; i <= n; ++i)
		for(register auto j = 1; j <= m; ++j)
		{
			bool x;
			cin >> x;
			if(x)
				h[i] = l[j] = true;
		}
	register auto hang = 0, lie = 0;
	for(register auto i = 1; i <= n; ++i)
		if(!h[i])
			++hang;
	for(register auto i = 1; i <= m; ++i)
		if(!l[i])
			++lie;
	register auto sum = hang * lie;
	cout << sum;
	return 0;
}