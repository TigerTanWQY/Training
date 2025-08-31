#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[1000003];
bool b[1000003];

void dfs(const int &p, bool f)
{
	if(b[p])
		f = true;
	b[p] = f;
	for(const auto &x: G[p])
		dfs(x, f);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	while(m--)
	{
		int u;
		scanf("%d", &u);
		b[u] = true;
	}
	dfs(1, false);
	for(int i = 1; i <= n; ++i)
		printf("%d", b[i]);
	return 0;
}