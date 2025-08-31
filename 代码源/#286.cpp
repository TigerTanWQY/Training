#include <cstdio>
using namespace std;

int main()
{
	int a, b, c, odd = 0, even = 0;
	scanf("%d%d%d", &a, &b, &c);
	if(a % 2)
		++odd;
	else
		++even;
	if(b % 2)
		++odd;
	else
		++even;
	if(c % 2)
		++odd;
	else
		++even;
	if(odd > even)
		printf("Odd");
	else
		printf("Even");
	return 0;
}