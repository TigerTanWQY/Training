#include <cstdio>
using namespace std;

int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	if(x < y)
		if(y - x <= 2)
			printf("Yes");
		else
			printf("No");
	else
		if(x - y <= 3)
			printf("Yes");
		else
			printf("No");
	return 0;
}