#include <bits/stdc++.h>
using namespace std;

struct Stu
{
	int zh, ma, en;
	int tot;
	int id;
} a[303];

bool cmp(const Stu &x, const Stu &y)
{
	if(x.tot != y.tot)
		return x.tot > y.tot;
	else if(x.zh != y.zh)
		return x.zh > y.zh;
	else
		return x.id < y.id;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &a[i].zh, &a[i].ma, &a[i].en);
		a[i].tot = a[i].zh + a[i].ma + a[i].en;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= 5; ++i)
		printf("%d %d\n", a[i].id, a[i].tot);
	return 0;
}