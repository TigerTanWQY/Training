#include <cstdio>
#include <cstring>
using namespace std;

char s1[103], s2[103], s3[103];

int main()
{
	int n, m = 0;
	scanf("%d%s%s", &n, s1 + 1, s2 + 1);
	for(int i = 1; i <= n; ++i)
		if(s1[i] == s2[i])
			s3[++m] = s1[i];
		else if(s1[i] > s2[i])
			s3[++m] = s2[i];
		else
		{
			printf("-1");
			return 0;
		}
	printf("%s", s3 + 1);
	return 0;
}