#include <cstdio>
using namespace std;

int main()
{
	int c;
	scanf("%d", &c);
	int a = c % 11, b = c % 31;
	if(a == 1)
	{
		if(b == 25)
			printf("C");
		else if(b == 14)
			printf("A");
	}
	else if(a == 3)
		if(b == 14)
			printf("C");
		else if(b == 25)
			printf("D");
	return 0;
}