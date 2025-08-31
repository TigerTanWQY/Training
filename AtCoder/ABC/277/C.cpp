#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> g;
queue<int> q;
set<int> s;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	q.push(1);
	s.insert(1);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(const int &i: g[v])
			if(!s.count(i))
			{
				q.push(i);
				s.insert(i);
			}
	}
	printf("%d", *s.crbegin());
	return 0;
}