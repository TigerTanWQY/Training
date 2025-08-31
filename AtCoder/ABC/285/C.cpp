#include <bits/stdc++.h>
using namespace std;

char str[15];

int main()
{
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	long long ans = 0, base = 1;
	for(int i = n; i; --i, base *= 26)
		ans += (str[i] - 'A' + 1) * base;
	printf("%lld", ans);
	return 0;
}