#include <cstdio>

int main()
{
	int n;
	std::scanf("%d", &n);
	std::printf("%d", (1 + n - !(n % 2)) * (n / 2 + n % 2) / 2);
	return 0;
}