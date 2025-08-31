#include <iostream>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
bool vis[131];
char to[20003];
int dis[131], head[131], nxt[20003], w[20003], cnt = 0;

inline void add(const char &x, const char &y, const int &v)
{
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	w[cnt] = v;
}

void Dijkstra(const char &s)
{
	for(int i = 0; i <= 128; ++i)
		dis[i] = INF;
	dis[s] = 0;
	priority_queue<pair<int, char>> q;
	q.push(make_pair(0, s));
	while(!q.empty())
	{
		char x = q.top().second;
		q.pop();
		if(vis[x])
			continue;
		else
			vis[x] = true;
		for(int i = head[x]; i; i = nxt[i])
		{
			char y = to[i];
			if(dis[x] + w[i] < dis[y])
			{
				dis[y] = dis[x] + w[i];
				q.push(make_pair(-dis[y], y));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int P;
	cin >> P;
	while(P--)
	{
		char x, y;
		int v;
		cin >> x >> y >> v;
		add(x, y, v);
		add(y, x, v);
	}
	Dijkstra('Z');
	char ans = 'A';
	for(char i = 'B'; i <= 'Y'; ++i)
		if(dis[i] < dis[ans])
			ans = i;
	cout << ans << " " << dis[ans];
	return 0;
}