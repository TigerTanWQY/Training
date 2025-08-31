#include <cstdio>

int main()
{
	int a, b, c;
	std::scanf("%d%d%d", &a, &b, &c);
	std::printf("%d", a + b > c && a + c > b && b + c > a);
	return 0;
}