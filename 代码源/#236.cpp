#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int a = n / 100, b = n / 10 % 10, c = n % 10;
	bool flag = false;
	if(c)
	{
		printf("%d", c);
		flag = true;
	}
	if(b || flag)
		printf("%d", b);
	printf("%d", a);
	return 0;
}