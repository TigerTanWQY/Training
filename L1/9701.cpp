#include <bits/stdc++.h>
using namespace std;

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a, b;
	cin >> a >> b;
	register auto ans = 0;
	while(!((a % 4 == 0 && a % 100 != 0) || a % 400 == 0))
		++a;
	for(register auto i = a; i <= b; i += 4)
		if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			++ans;
	cout << ans;
	return 0;
}