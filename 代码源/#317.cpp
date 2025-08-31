#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if(n / 100 == n % 100)
		printf("YES");
	else
		printf("NO");
	return 0;
}