#include <bits/stdc++.h>
using namespace std;

struct Data
{ int id, score; }
a[5003];

bool cmp(const Data &x, const Data &y)
{
	if(x.score != y.score)
		return x.score > y.score;
	else
		return x.id < y.id;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].id, &a[i].score);
	sort(a + 1, a + n + 1, cmp);
	int line = a[static_cast<int>(m * 1.5)].score;
	int ans = 0;
	for(int i = 1; a[i].score >= line; ++i)
		++ans;
	printf("%d %d\n", line, ans);
	for(int i = 1; i <= ans; ++i)
		printf("%d %d\n", a[i].id, a[i].score);
	return 0;
}