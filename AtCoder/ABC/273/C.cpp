#include <bits/stdc++.h>
using namespace std;

map<int, int> m; //不能用常规数组

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		++m[a];
	}
	for(auto crit = m.crbegin(); crit != m.crend(); ++crit)
		printf("%d\n", crit->second);
	for(int i = 0; i < n - m.size(); ++i)
		printf("0\n");
	return 0;
}