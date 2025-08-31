#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a[8003];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, maxlen = 0, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxlen = max(maxlen, (int)a[i].size());
	}
	for(int i = 1; i <= n; ++i)
	{
		int k = maxlen - a[i].size();
		while(k--)
			a[i].insert(a[i].cbegin(), '0');
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; ++i)
	{
		int cnt = 0;
		for(int x = 0; x < a[i].size(); ++x)
			cnt += (a[i][x] != a[i + 1][x]);
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}