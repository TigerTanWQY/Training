#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[100003];
queue<int> q;
int d[100003]{0, 1};

void getd(const int &p)
{
	q.push(p);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		for(const auto &x: G[f])
		{
			d[x] = d[f] + 1;
			q.push(x);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	getd(1);
	for(int i = 1; i <= n; ++i)
		printf("%d ", d[i]);
	return 0;
}