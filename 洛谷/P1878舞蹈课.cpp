#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Data
{
	int w, c, d;
	bool operator<(const Data &A) const
	{
		if(w != A.w)
			return w > A.w;
		return c > A.c;
	}
};
bool vis[200003];
int a[200003], ans1[200003], ans2[200003], f[200003], g[200003], k = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	priority_queue<Data> q;
	s += 'H';
	for(int i = 1; i < n; ++i)
		if(s[i - 1] != s[i])
			q.push({abs(a[i] - a[i + 1]), i, i + 1});
	for(int i = 1; i <= n; ++i)
	{
		f[i] = i + 1;
		g[i] = i - 1;
	}
	while(!q.empty())
	{
		auto t = q.top();
		q.pop();
		int x = t.c, y = t.d;
		if(!vis[x] && !vis[y])
		{
			f[g[x]] = f[y];
			g[f[y]] = g[x];
			ans1[++k] = x;
			ans2[k] = y;
			vis[x] = vis[y] = true;
			if(!vis[g[x]] && !vis[f[y]])
				if((s[g[x] - 1] + s[f[y] - 1]) == ('G' + 'B'))
					q.push({abs(a[g[x]] - a[f[y]]), g[x], f[y]});
		}
	}
	cout << k << "\n";
	for(int i = 1; i <= k; ++i)
		cout << ans1[i] << " " << ans2[i] << "\n";
	return 0;
}