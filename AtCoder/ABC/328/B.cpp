#include <cstdio>
using namespace std;

int d[103];

bool check(int x)
{
	for(; x / 10; x /= 10)
		if(x % 10 != x / 10 % 10)
			return false;
	return true;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	for(int i = 1; i <= n; ++i)
		if(check(i))
			for(int j = i % 10; j <= d[i]; j += j * 10)
				if(j % 10 == i % 10 && check(j))
					++ans;
	printf("%d", ans);
	return 0;
}