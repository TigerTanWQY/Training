#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int d = n % 10, c = n / 10 % 10, b = n / 100 % 10, a = n / 1000;
	if(a == b && b == c && c == d)
		printf("Weak");
	else if(b == (a + 1) % 10 && c == (b + 1) % 10 && d == (c + 1) % 10)
		printf("Weak");
	else
		printf("Strong");
	return 0;
}