#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[100003];

int dist(const int &x1, const int &y1, const int &x2, const int &y2)
{ return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x1, y1, x2, y2, n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	for(int i = 1, x, y; i <= n; ++i)
	{
		cin >> x >> y;
		a[i].first = dist(x1, y1, x, y);
		a[i].second = dist(x2, y2, x, y);
	}
	sort(a + 1, a + n + 1);
	int ans = a[n].first, hei = -1;
	for(int i = n - 1; i; --i)
	{
		hei = max(hei, a[i + 1].second);
		ans = min(ans, hei + a[i].first);
	}
	cout << ans;
	return 0;
}