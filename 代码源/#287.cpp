#include <cstdio>
using namespace std;

int main()
{
	int x, a, b, c;
	scanf("%d%d%d%d", &x, &a, &b, &c);
	if(x > a)
		printf("һ�Ƚ�");
	else if(x > b)
		printf("���Ƚ�");
	else if(x > c)
		printf("���Ƚ�");
	else
		printf("û��");
	return 0;
}