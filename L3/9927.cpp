#include <bits/stdc++.h>
using namespace std;

struct Kuai
{
	int st, ed, th;
	Kuai() = default;
	Kuai(const int &_st, const int &_ed, const int &_th)
	: st(_st), ed(_ed), th(_th)
	{ }
};
bool used[200003];
int t[200003];
queue<Kuai> q1, q2;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	t[n + 1] = !t[n];
	for(int i = 2, si = 1; i <= n + 1; ++i)
		if(t[i] != t[i - 1])
		{
			q1.push(Kuai{si, i - 1, t[i - 1]});
			si = i;
		}
	int cnt = n;
	while(cnt)
	{
		while(!q1.empty())
		{
			Kuai f = q1.front();
			q1.pop();
			while(used[f.st] && f.st <= f.ed)
				++f.st;
			if(f.st > f.ed)
				continue;
			printf("%d ", f.st);
			--cnt;
			used[f.st] = true;
			if(f.ed == f.st)
				continue;
			++f.st;
			q2.push(f);
		}
		printf("\n");
		while(!q2.empty())
		{
			Kuai ad = q2.front();
			q2.pop();
			while(!q2.empty())
			{
				Kuai x = q2.front();
				if(x.th == ad.th)
				{
					ad.ed = x.ed;
					q2.pop();
				}
				else
					break;
			}
			q1.push(ad);
		}
	}
	return 0;
}