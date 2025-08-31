#include <cstdio>
#include <algorithm>
#include <functional>

int a[5];

int main()
{
	std::scanf("%d%d%d%d%d", a, a + 1, a + 2, a + 3, a + 4);
	std::sort(a, a + 5, std::greater<int>());
	std::printf("%d,%d,%d,%d,%d", a[0], a[1], a[2], a[3], a[4]);
	return 0;
}