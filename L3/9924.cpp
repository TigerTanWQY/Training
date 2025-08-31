#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int INF = 0x3f3f3f3f;
const LL MOD = 1e9 + 7;
const int N = 1000003;

stack<int> b;
char s[N];
int a[N], son[N][2], ck;
bool flag[N], c[N];
int n;

int dfs(const int &u, const int &g)
{
	a[u] ^= g;
	if(u <= n)
		return a[u];
	int L = son[u][0], R = son[u][1];
	int x = dfs(L, g ^ flag[L]), y = dfs(R, g ^ flag[R]);
	if(a[u] == 2)
	{
		if(x == 0)
			c[R] = true;
		if(y == 0)
			c[L] = true;
		return x & y;
	}
	else
	{
		if(x == 1)
			c[R] = true;
		if(y == 1)
			c[L] = true;
		return x | y;
	}
}

void dfs2(const int &u)
{
	if(u <= n)
		return;
	int L = son[u][0], R = son[u][1];
	c[L] |= c[u];
	c[R] |= c[u];
	dfs2(L);
	dfs2(R);
}

int main()
{
	int q;
	cin.getline(s, N);
	scanf("%d", &n);
	ck = n;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; s[i]; i += 2)
		if(s[i] == 'x')
		{
			int x = 0;
			++i;
			while(s[i] != ' ')
				x = x * 10 + s[i++] - '0';
			--i;
			b.push(x);
		}
		else if(s[i] == '&' || s[i] == '|')
		{
			int x = b.top();
			b.pop();
			int y = b.top();
			b.pop();
			b.push(++ck);
			if(s[i] == '&')
				a[ck] = 2;
			else
				a[ck] = 3;
			son[ck][0] = x;
			son[ck][1] = y;
		}
		else if(s[i] == '!')
			flag[b.top()] ^= 1;
	int ans = dfs(ck, flag[ck]);
	dfs2(ck);
	scanf("%d", &q);
	while(q--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", c[x]? ans: !ans);
	}
	return 0;
}