#include <cstdio>
#include <algorithm>
using namespace std;

char s[100003];
int n, l, k, ans = 2147483647;

inline bool check()
{
	char last = '\0';
	int cnt = 0;
	for(int i = 1; i <= n; last = s[i++])
		if(s[i] != last)
			++cnt;
	return cnt <= k;
}

void dfs(const int &x, const int &cnt)
{
	if(x > n)
	{
		if(check())
			ans = min(ans, cnt);
		return;
	}
	char tmp = s[x];
	for(char ch = 'a'; ch <= 'z'; ++ch)
	{
		s[x] = ch;
		dfs(x + 1, cnt + 1);
		s[x] = tmp;
		dfs(x + 1, cnt);
	}
}

int main()
{
	scanf("%d%d%d%s", &n, &l, &k, s + 1);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}