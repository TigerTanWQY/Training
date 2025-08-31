#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	freopen("sort.in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 999999 + 1, m = rand() % 999999 + 1;
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; ++i)
		printf("%d ", rand() % 1000001 - 500000);
	fclose(stdout);
	return 0;
}