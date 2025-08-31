#include <bits/stdc++.h>
using namespace std;

vector<int> v[100003];
int odd[100003], even[100003];

void bfw()
{
	memset(odd, 0x3f, sizeof(odd));
	memset(even, 0x3f, sizeof(even));
	queue<pair<int, int>> q;
	for(int i = 0; i < v[1].size(); ++i)
	{
		odd[v[1][i]] = 1;
		q.push(make_pair(v[1][i], 1));
	}
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		for(int i = 0; i < v[x].size(); ++i)
		if(y % 2 == 1)
		{
			if(y + 1 < even[v[x][i]])
			{
				even[v[x][i]] = y + 1;
				q.push(make_pair(v[x][i], y + 1));
			}
		}
		else if(y + 1 < odd[v[x][i]])
		{
			odd[v[x][i]] = y + 1;
			q.push(make_pair(v[x][i], y + 1));
		}
		q.pop();
	}
}

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfw();
	while(q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(y % 2 == 0)
			if(even[x] > y)
				printf("No\n");
			else
				printf("Yes\n");
		else
			if(odd[x] > y)
				printf("No\n");
			else
				printf("Yes\n");
	}
	return 0;
}