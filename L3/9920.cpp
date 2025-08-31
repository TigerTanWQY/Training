#include <bits/stdc++.h>
using namespace std;

int t[4000003], s[4000003], f[4000003], d[4000003];

double slope(const int &a, const int &b)
{
	if(t[b] == t[a])
		return (f[b] + s[b] - f[a] - s[a]) * 4000000;
	return 1.0 * (f[b] + s[b] - f[a] - s[a]) / (t[b] - t[a]);
}

int main()
{
	int n, m, maxn = 0, l = 1, r = 0, ans = 0x3f3f3f3f;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		maxn = max(maxn, a);
		++t[a];
		s[a] += a;
	}
	for(int i = 1; i < maxn + n; ++i)
	{
		t[i] += t[i - 1];
		s[i] += s[i - 1];
	}
	for(int i = 0; i < maxn + m; ++i)
	{
		if(i - m >= 0)
		{
			while(l < r && slope(d[r - 1], d[r]) >= slope(d[r], i - m))
				--r;
			d[++r] = i - m;
		}
		while(l < r && slope(d[l], d[l + 1]) <= i)
			++l;
		f[i] = t[i] * i - s[i];
		if(l <= r)
			f[i] = min(f[i], f[d[l]] + (t[i] - t[d[l]]) * i - (s[i] - s[d[l]]));
	}
	for(int i = maxn; i < maxn + m; ++i)
		ans = min(ans, f[i]);
	printf("%d", ans);
	return 0;
}