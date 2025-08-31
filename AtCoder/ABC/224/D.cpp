#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

vector<int> edges[12];
queue<string> q;
map<string, int> mp;

int main()
{
	int m;
	scanf("%d", &m);
	for(int u, v; m; --m)
	{
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	string str = "999999999";
	for(int i = 1, p; i < 9; ++i)
	{
		scanf("%d", &p);
		str[p - 1] = '0' + i;
	}
	q.push(str);
	mp[str] = 0;
	for(string s; !q.empty(); )
	{
		s = q.front();
		q.pop();
		int v = 0;
		for(int i = 1; !v && i <= 9; ++i)
			if(s[i - 1] == '9')
				v = i;
		int len = edges[v].size();
		for(int i = 0; i < len; ++i)
		{
			string t = s;
			swap(t[edges[v][i] - 1], t[v - 1]);
			if(mp.find(t) != mp.cend())
				continue;
			mp[t] = mp[s] + 1;
			q.push(t);
		}
	}
	if(mp.find("123456789") == mp.cend())
		printf("-1");
	else
		printf("%d", mp["123456789"]);
	return 0;
}