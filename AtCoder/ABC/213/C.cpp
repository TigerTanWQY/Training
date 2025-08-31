#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> h, w;
int x[100003], y[100003];

int main()
{
	int H, W, N, cnt = 0;
	scanf("%d%d%d", &H, &W, &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d%d", &y[i], &x[i]);
		h[y[i]] = 1;
		w[x[i]] = 1;
	}
	for(auto &p: w)
		p.second = ++cnt;
	cnt = 0;
	for(auto &p: h)
		p.second = ++cnt;
	for(int i = 0; i < N; ++i)
		printf("%d %d\n", h[y[i]], w[x[i]]);
	return 0;
}