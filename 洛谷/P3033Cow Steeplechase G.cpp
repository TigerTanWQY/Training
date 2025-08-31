#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 62503;
vector<int> G[N];
bool vis[N];
int p[4][N], f[N], match[N];

bool dfs(const int &u) {
	for(const auto &v: G[u])
		if(!vis[v])	{
			vis[v] = true;
			if(!match[v] || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
	return false;
}

int main() {
	int n, os = 0, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &p[0][i], &p[1][i], &p[2][i], &p[3][i]);
		if(p[0][i] > p[2][i])
			swap(p[0][i], p[2][i]);
		if(p[1][i] > p[3][i])
			swap(p[1][i], p[3][i]);
		if(p[0][i] == p[2][i]) {
			f[i] = 1;
			++os;
		}
		else
			f[i] = 2;
	}
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			if(f[i] == 1 && f[j] == 2 && p[0][j] <= p[0][i] && p[2][j] >= p[0][i] && p[1][j] <= p[3][i] && p[1][j] >= p[1][i])
				G[i].push_back(j + os);
			if(f[i] == 2 && f[j] == 1 && p[1][j] <= p[1][i] && p[3][j] >= p[1][i] && p[0][j] >= p[0][i] && p[0][j] <= p[2][i])
				G[j].push_back(i + os);
		}
	for(int i = 1; i <= n; ++i)
		if(f[i] == 1) {
			memset(vis, false, sizeof(vis));
			if(dfs(i))
				++ans;
		}
	printf("%d", n - ans);
	return 0;
}
