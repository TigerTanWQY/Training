#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int a[1003], q[1003], m;

int solve(int x, const int &sign, const bool &flag)
{
	for(int cnt = 0; x < m; ++x)
	{
		if(s[x] == '(')
			++cnt;
		else if(s[x] == ')')
			--cnt;
		else if(s[x] == 'X')
		{
			++x;
			int num = 0;
			for(; '0' <= s[x] && s[x] <= '9'; ++x)
				num = num * 10 + s[x] - '0';
			--x;
			q[num] += sign;
		}
		else if(s[x] == '-')
		{
			if(cnt == 0 && flag)
			{
				--x;
				break;
			}
			x = solve(x + 1, -sign, true);
		}
		else if(cnt == 0 && flag)
		{
			--x;
			break;
		}
		if(cnt < 0)
		{
			--x;
			break;
		}
	}
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n >> s;
	m = s.length();
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	solve(0, 1, false);
	sort(q + 1, q + n + 1);
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += 1LL * a[i] * q[i];
	cout << ans << " ";
	reverse(a + 1, a + n + 1);
	ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += 1LL * a[i] * q[i];
	cout << ans;
	return 0;
}