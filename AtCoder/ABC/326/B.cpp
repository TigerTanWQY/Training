#include <cstdio>
using namespace std;

bool check(const int &m)
{
	int x = m / 100, y = m / 10 % 10, z = m % 10;
	return x * y == z;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = n; ; ++i)
		if(check(i))
		{
			printf("%d", i);
			break;
		}
	return 0;
}