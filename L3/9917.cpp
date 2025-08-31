#include <bits/stdc++.h>
using namespace std;

struct Boat
{ int t, nat; };
queue<Boat> q;
map<int, int> cnt;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	while(n--)
	{
		int t, k;
		scanf("%d%d", &t, &k);
		Boat tmp;
		while(!q.empty() && t - q.front().t >= 86400)
		{
			tmp = q.front();
			q.pop();
			--cnt[tmp.nat];
			if(cnt[tmp.nat] <= 0)
				--ans;
		}
		for(int i = 1; i <= k; ++i)
		{
			int ntl;
			scanf("%d", &ntl);
			tmp.nat = ntl;
			tmp.t = t;
			q.push(tmp);
			++cnt[tmp.nat];
			if(cnt[tmp.nat] == 1)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}