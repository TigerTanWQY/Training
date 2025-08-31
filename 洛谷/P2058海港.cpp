#include <cstdio>
#include <vector>
using namespace std;

const int N = 100003;
struct Boat
{
	int t;
	vector<int> x;
} p[N]{};
int q[N], vis[N], f = 1, r = 0, ans = 0;

void add(const int &id)
{
	for(const auto &y: p[id].x)
	{
		++vis[y];
		if(vis[y] == 1)
			++ans;
	}
}

void del(const int &id)
{
	for(const auto &y: p[id].x)
	{
		--vis[y];
		if(vis[y] == 0)
			--ans;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0, m; i < n; ++i)
	{
		scanf("%d%d", &p[i].t, &m);
		for(int y; m--; p[i].x.push_back(y))
			scanf("%d", &y);
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