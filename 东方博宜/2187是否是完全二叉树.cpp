#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[1027];
bool vis[1027];

bool is_CBT(const int &root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
	{
        int f = q.front();
        q.pop();
        bool flag = false;
		for(const auto &p: G[f])
			if(!vis[p])
			{
				flag = vis[p] = true;
				q.push(p);
			}
		if(!flag)
			while(!q.empty())
			{
				flag = false;
				f = q.front();
				q.pop();
				for(const auto &p: G[f])
					if(!vis[p])
					{
						flag = true;
						break;
					}
				if(flag)
					return false;
			}
    }
    return true;
}

int main()
{
	int n, r;
	scanf("%d%d", &n, &r);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(is_CBT(r))
		printf("yes");
	else
		printf("no");
	return 0;
}