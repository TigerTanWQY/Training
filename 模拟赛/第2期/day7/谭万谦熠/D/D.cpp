#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[100003];

inline bool is_lucky(int x)
{
	for(; x; x /= 10)
		if(x % 10 != 4 && x % 10 != 7)
			return false;
	return true;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int _ = 1; _ < n; ++_)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(is_lucky(w))
		{
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	for(int i = 1; i <= n; ++i) // สýังปฏ
		ans += G[i].size();
	printf("%d", 4 * ans);
	return 0;
}