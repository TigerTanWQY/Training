#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int P = 100003;
const int N = 1000003;
vector<int> G[N];
bool vis[N];
int dep[N], cnt[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	queue<int> q;
	dep[1] = 0;
	vis[1] = true;
	cnt[1] = 1;
	q.push(1);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(const auto &t: G[x])
		{
			if(!vis[t])
			{
				vis[t] = true;
				dep[t] = dep[x] + 1;
				q.push(t);
			}
			if(dep[t] == dep[x] + 1)
				cnt[t] = (cnt[t] + cnt[x]) % P;
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d\n", cnt[i]);
	return 0;
}