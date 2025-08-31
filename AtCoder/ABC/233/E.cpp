#include <cstdio>
#include <cstring>
using namespace std;

char x[500003], ans[500003];

int main()
{
	scanf("%s", x);
	int n = strlen(x), m = 0, tot1 = 0, tot2 = 0;
	for(int i = 0; i < n; ++i)
		tot1 += x[i] - '0';
	for(int i = n - 1; i >= 0 || tot2; --i)
	{
		tot2 += tot1;
		ans[m++] = '0' + tot2 % 10;
		tot2 /= 10;
		if(i >= 0)
			tot1 -= x[i] - '0';
	}
	for(int i = m - 1; i >= 0; --i)
		printf("%c", ans[i]);
	return 0;
}