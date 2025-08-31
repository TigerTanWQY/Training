#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[200003];
int cnt[200003];

int main()
{
	int k, ans = 0;
	scanf("%s%d", s + 1, &k);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; ++i)
	{
		cnt[i + 1] = cnt[i];
		if(s[i] == '.')
			++cnt[i + 1];
	}
	for(int L = 1, R = 1; L <= n; ++L)
	{
		while(R <= n && cnt[R + 1] - cnt[L] <= k)
			++R;
		ans = max(ans, R - L);
	}
	printf("%d", ans);
	return 0;
}