#include <cstdio>
using namespace std;

int main()
{
	int x, a, b, c;
	scanf("%d%d%d%d", &x, &a, &b, &c);
	if(x > a)
		printf("一等奖");
	else if(x > b)
		printf("二等奖");
	else if(x > c)
		printf("三等奖");
	else
		printf("没获奖");
	return 0;
}