#include <iostream>
#include <string>
using namespace std;

int m;
string n, ans;

void solve(const int &x)
{
	if(x > m)
	{
		for(int _ = 0; _ < x / 2; ++_)
			ans += '4';
		for(int _ = 0; _ < x / 2; ++_)
			ans += '7';
		return;
	}
	int cnt4 = 0, cnt7 = 0, idx = 0, lcnt4 = 0, lcnt7 = 0;
	for(int i = 0; i < x; ++i)
		if(n[i] < '4')
		{
			for(; cnt4 < x / 2; ++cnt4)
				ans += '4';
			for(; cnt7 < x / 2; ++cnt7)
				ans += '7';
			return;
		}
		else if(n[i] == '4')
			if(cnt4 < x / 2)
			{
				if(cnt7 < x / 2)
				{
					idx = i;
					lcnt4 = cnt4;
					lcnt7 = cnt7;
				}
				ans += '4';
				++cnt4;
			}
			else
			{
				for(; cnt7 < x / 2; ++cnt7)
					ans += '7';
				return;
			}
		else if(n[i] < '7')
			if(cnt7 < x / 2)
			{
				ans += '7';
				++cnt7;
				for(; cnt4 < x / 2; ++cnt4)
					ans += '4';
				for(; cnt7 < x / 2; ++cnt7)
					ans += '7';
				return;
			}
			else
			{
				i = idx;
				cnt4 = lcnt4;
				cnt7 = lcnt7;
				ans = ans.substr(0, cnt4 + cnt7);
				ans += '7';
				++cnt7;
				for(; cnt4 < x / 2; ++cnt4)
					ans += '4';
				for(; cnt7 < x / 2; ++cnt7)
					ans += '7';
				return;
			}
		else if(n[i] == '7')
			if(cnt7 < x / 2)
			{
				ans += '7';
				++cnt7;
			}
			else
			{
				i = idx;
				cnt4 = lcnt4;
				cnt7 = lcnt7;
				ans = ans.substr(0, cnt4 + cnt7);
				ans += '7';
				++cnt7;
				for(; cnt4 < x / 2; ++cnt4)
					ans += '4';
				for(; cnt7 < x / 2; ++cnt7)
					ans += '7';
				return;
			}
		else
		{
			i = idx;
			cnt4 = lcnt4;
			cnt7 = lcnt7;
			ans = ans.substr(0, cnt4 + cnt7);
			ans += '7';
			++cnt7;
			for(; cnt4 < x / 2; ++cnt4)
				ans += '4';
			for(; cnt7 < x / 2; ++cnt7)
				ans += '7';
			return;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		m = n.size();
		if(m & 1)
		{
			solve(m + 1);
			cout << ans << "\n";
			ans.clear();
			continue;
		}
		for(int i = 0; i < m / 2; ++i)
			if(n[i] < '7')
			{
				solve(m);
				break;
			}
			else if(n[i] > '7')
			{
				solve(m + 2);
				break;
			}
		if(ans.empty())
			for(int i = m / 2; i < m; ++i)
				if(n[i] < '4')
				{
					solve(m);
					break;
				}
				else if(n[i] > '4')
				{
					solve(m + 2);
					break;
				}
		if(ans.empty())
			solve(m);
		cout << ans << "\n";
		ans.clear();
	}
	return 0;
}