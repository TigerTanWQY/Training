#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using LL = long long;

const int N = 200003;
vector<int> a[3];
LL x[N], y[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, r = 0;
	cin >> n >> m;
	a[0].reserve(n);
	a[1].reserve(n);
	a[2].reserve(n);
	for(int i = 0; i < n; ++i)
	{
		int _t, _x;
		cin >> _t >> _x;
		if(_t == 0)
			a[0].push_back(_x);
		else if(_t == 1)
			a[1].push_back(_x);
		else
			a[2].push_back(_x);
	}
	sort(a[0].begin(), a[0].end(), greater<>());
	sort(a[1].begin(), a[1].end());
	sort(a[2].begin(), a[2].end());
	for(int i = 0; i < n; ++i)
		if(i < a[0].size())
			x[i + 1] = x[i] + a[0][i];
		else
			x[i + 1] = x[i];
	for(int i = 0; i < n; ++i)
		if(a[1].empty())
			y[i + 1] = y[i];
		else if(r == 0)
		{
			if(!a[2].empty())
			{
				r += a[2].back();
				a[2].pop_back();
			}
			y[i + 1] = y[i];
		}
		else
		{
			--r;
			y[i + 1] = y[i] + a[1].back();
			a[1].pop_back();
		}
	LL ans = 0;
	for(int i = 0; i <= m; ++i)
		if(x[i] + y[m - i] > ans)
			ans = x[i] + y[m - i];
	cout << ans;
	return 0;
}