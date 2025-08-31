#include <cstdio>
#include <algorithm>
using namespace std;

struct Player
{
	int s, w, id;
	bool operator<(const Player &A) const
	{
		if(s != A.s)
			return s > A.s;
		else
			return id < A.id;
	}
} a[200003];

int main()
{
	freopen("..\\data.out", "r", stdin);
	int n, r, q;
	scanf("%d%d%d", &n, &r, &q);
	n <<= 1;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].s);
		a[i].id = i;
	}
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].w);
	stable_sort(a + 1, a + n + 1);
	while(r--)
	{
		for(int i = 1; i < n; i += 2)
			if(a[i].w > a[i + 1].w)
				++a[i].s;
			else if(a[i].w < a[i + 1].w)
				++a[i + 1].s;
		stable_sort(a + 1, a + n + 1);
	}
	printf("%d", a[q].id);
	return 0;
}