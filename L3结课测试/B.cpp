#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100003];
int dfs[100003], minans[100003], maxans[100003], n, len = 0;

void pre(const int &p)
{
	dfs[++len] = p;
	for(const auto &x: edges[p])
		pre(x);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		for(int i = 0; i < 100003; ++i)
			edges[i].clear();
		memset(minans, 0x3f, sizeof(minans));
		memset(maxans, 0, sizeof(maxans));
		scanf("%d", &n);
		for(int _ = 1; _ < n; ++_)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			edges[x].push_back(y);
		}
		for(int i = 1; i <= n; ++i)
			sort(edges[i].begin(), edges[i].end());
		do
		{
			len = 0;
			pre(1);
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= len; ++j)
					if(i == dfs[j])
					{
						minans[i] = min(minans[i], j);
						maxans[i] = max(maxans[i], j);
						break;
					}
			for(int i = 1; i <= n; ++i)
				next_permutation(edges[i].begin(), edges[i].end());
			if(!next_permutation(edges + 1, edges + n + 1))
				break;
		} while(true);
		for(int i = 1; i <= n; ++i)
			printf("%d %d\n", minans[i], maxans[i]);
	}
	return 0;
}