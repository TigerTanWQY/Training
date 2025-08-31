#include <bits/stdc++.h>
using namespace std;

char s[103];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	cin >> (s + 1) >> m;
	register auto n = static_cast<int>(strlen(s + 1));
	for(register auto i = 1; i <= m; ++i)
	{
		for(register auto j = 1; j <= n; ++j)
			s[j - 1] = s[j];
		s[n] = s[0];
	}
	cout << (s + 1);
	return 0;
}