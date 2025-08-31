#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[100003];
int d[100003]{0, 1};

void getd(const int &p)
{
	for(const auto &x: G[p])
	{
		d[x] = d[p] + 1;
		getd(x);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	getd(1);
	for(int i = 1; i <= n; ++i)
		printf("%d ", d[i]);
	return 0;
}