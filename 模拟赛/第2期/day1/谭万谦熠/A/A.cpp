#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	double ans = 0.00;
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		if(ans < 100)
			ans += x;
		else if(ans < 150)
			ans += x * 4.0 / 5;
		else if(ans < 400)
			ans += x / 2.0;
		else
			ans += x;
	}
	printf("%.2lf", ans);
	return 0;
}