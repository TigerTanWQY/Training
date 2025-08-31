#include <bits/stdc++.h>
using namespace std;

struct Player
{
	int s, id, w;
	bool operator<(const Player &A) const
	{
		if(s != A.s)
			return s > A.s;
		return id < A.id;
	}
} p[200003], loser[200003], winer[200003];

int main()
{
	int n, r, q;
	scanf("%d%d%d", &n, &r, &q);
	for(int i = 1; i <= 2 * n; ++i)
	{
		scanf("%d", &p[i].s);
		p[i].id = i;
	}
	for(int i = 1; i <= 2 * n; ++i)
		scanf("%d", &p[i].w);
	sort(p + 1, p + 2 * n + 1);
	while(r--)
	{
		for(int i = 1; i <= n; ++i)
			if(p[2 * i - 1].w < p[2 * i].w)
			{
				++p[2 * i].s;
				loser[i] = p[2 * i - 1];
				winer[i] = p[2 * i];
			}
			else
			{
				++p[2 * i - 1].s;
				loser[i] = p[2 * i];
				winer[i] = p[2 * i - 1];
			}
		merge(loser + 1, loser + n + 1, winer + 1, winer + n + 1, p + 1);
	}
	printf("%d", p[q].id);
	return 0;
}