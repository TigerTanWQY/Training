#include <bits/stdc++.h>
using namespace std;

struct Info
{ int s0, s1; };
const int MOD = 10007;
const int N = 100003;
char s[N];
int l1[N], l2[N], c1[N], c2[N];

Info calc(const int &l, const int &r)
{
	if(l > r)
		return Info{1, 1};
	if(l1[r] >= l)
	{
		Info ansl = calc(l, l1[r] - 1), ansr = calc(l1[r] + 1, r);
		return Info{ansl.s0 * ansr.s0 % MOD, (ansl.s0 * ansr.s1 + ansl.s1 * ansr.s0 + ansl.s1 * ansr.s1) % MOD};
	}
	if(l2[r] >= l)
	{
		Info ansl = calc(l, l2[r] - 1), ansr = calc(l2[r] + 1, r);
		return Info{(ansl.s0 * ansr.s1 + ansl.s1 * ansr.s0 + ansl.s0 * ansr.s0) % MOD, ansl.s1 * ansr.s1 % MOD};
	}
	if(s[l] == '(' && s[r] == ')')
		return calc(l + 1, r - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	if(n == 0)
	{
		printf("1");
		return 0;
	}
	scanf("%s", s + 1);
	int x = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else if(s[i] == '+')
			c1[x] = i;
		else if(s[i] == '*')
			c2[x] = i;
		l1[i] = c1[x];
		l2[i] = c2[x];
	}
	Info ans = calc(1, n);
	printf("%d", ans.s0);
	return 0;
}