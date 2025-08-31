#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
vector<int> inv[N];
int a[N], b[N], cnt[N], ans[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for(int i = 0; i < n; i++)
	{
		inv[a[i]].push_back(i);
		inv[b[i]].push_back(i);
	}
	int cnt_zero = n;
	for(int i = 1, j = 1; i <= m; ++i)
	{
		for(; j <= m && cnt_zero; ++j)
			for(const auto &x: inv[j])
			{
				if(cnt[x] == 0)
					cnt_zero--;
				cnt[x]++;
			}
		if(cnt_zero)
			break;
		ans[j - i]++;
		ans[m - i + 2]--;
		for(const auto &x: inv[i])
		{
			cnt[x]--;
			if(!cnt[x])
				cnt_zero++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		ans[i] += ans[i - 1];
		printf("%d ", ans[i]);
	}
	return 0;
}