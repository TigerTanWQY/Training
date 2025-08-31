#include <cstdio>
#include <algorithm>
using namespace std;

char s[100003];

int main()
{
	int L, R;
	scanf("%d%d%s", &L, &R, s + 1);
	for(int i = L, j = R; i < j; ++i, --j)
		swap(s[i], s[j]);
	printf("%s", s + 1);
	return 0;
}