#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, ans = 0;
	scanf("%d%d", &x, &y);
	for(int i = 1; 1LL * i * i <= 1LL * x * y; ++i)
		if(!((1LL * x * y) % i) && __gcd(1LL * i, (1LL * x * y) / i) == x)
		{
			if(1LL * i * i != 1LL * x * y)
				++ans;
			++ans;
		}
	printf("%d", ans);
	return 0;
}