#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int m, s, t, s1 = 0, s2 = 0;
	scanf("%d%d%d", &m, &s, &t);
	for(int i = 1; i <= t; ++i)
	{
		s1 += 17;
		if(m >= 10)
		{
			s2 += 60;
			m -= 10;
		}
		else
			m += 4;
		s1 = max(s1, s2);
		if(s1 > s)
		{
			printf("Yes\n%d", i);
			return 0;
		}
	}
	printf("No\n%d", s1);
	return 0;
}