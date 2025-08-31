#include <cstdio>
using namespace std;

const int md[]{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int m, d;
	scanf("%d%d", &m, &d);
	int ans = md[m] - d + 1;
	for(int i = m + 1; i <= 12; ++i)
		ans += md[i];
	printf("%d", ans);
	return 0;
}