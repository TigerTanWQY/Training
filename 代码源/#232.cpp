#include <cstdio>
using namespace std;

int main()
{
	int x;
	scanf("%d", &x);
	if(x >= 90)
		printf("A");
	else if(x >= 80)
		printf("B");
	else if(x >= 60)
		printf("C");
	else
		printf("D");
	return 0;
}