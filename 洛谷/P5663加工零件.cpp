#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 100003;
vector<int> v[N];
int odd[N], even[N];

void bfw()
{
	memset(odd, 0x3f, sizeof(odd));
	memset(even, 0x3f, sizeof(even));
	queue<pair<int, int>> q;
	for(int i = 0; i < v[1].size(); ++i)
	{
		odd[v[1][i]] = 1;
		q.push({v[1][i], 1});
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
					q.push({v[x][i], y + 1});
				}
			}
			else if(y + 1 < odd[v[x][i]])
			{
				odd[v[x][i]] = y + 1;
				q.push({v[x][i], y + 1});
			}
		q.pop();
	}
}

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	while(m--)
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
		if(y % 2)
			if(odd[x] > y)
				printf("No\n");
			else
				printf("Yes\n");
		else
			if(even[x] > y)
				printf("No\n");
			else
				printf("Yes\n");
	}
	return 0;
}