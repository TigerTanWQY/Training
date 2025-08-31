#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int a[4003];

int main()
{
	int n, ans = 1e9;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		bool flag = false;
		int cnt = 0;
		for(int j = i; j < i + n; ++j)
		{
			if(q.empty() && !a[j])
			{
				flag = true;
				break;
			}
			for(int k = a[j]; k--; )
				q.push(j);
			int t = q.top();
			q.pop();
			cnt += (j - t) * (j - t);
		}
		if(flag)
			continue;
		ans = min(ans, cnt);
	}
	printf("%d", ans);
	return 0;
}