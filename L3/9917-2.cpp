#include <bits/stdc++.h>
using namespace std;

struct Boat
{
	int t;
	vector<int> x;
} p[100003]{};
int q[100003], vis[100003], ans;

void add(const int &id)
{
	int m = p[id].x.size();
	for(int i = 0; i < m; ++i)
	{
		int y = p[id].x[i];
		++vis[y];
		if(vis[y] == 1)
			++ans;
	}
}

void del(const int &id)
{
	int m = p[id].x.size();
	for(int i = 0; i < m; ++i)
	{
		int y = p[id].x[i];
		--vis[y];
		if(vis[y] == 0)
			--ans;
	}
}

int main()
{
	int n, f = 1, r = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &p[i].t);
		int m;
		scanf("%d", &m);
		while(m--)
		{
			int y;
			scanf("%d", &y);
			p[i].x.push_back(y);
		}
	}
	for(int i = 0; i < n; ++i)
	{
		q[++r] = i;
		add(i);
		while(f <= r && p[q[f]].t <= p[i].t - 86400)
			del(q[f++]);
		printf("%d\n", ans);
	}
	return 0;
}