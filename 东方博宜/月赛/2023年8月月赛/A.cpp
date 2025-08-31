#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char n[11];

int main()
{
	scanf("%s", n);
	int m = strlen(n), minn = 2147483647, mini = -1, maxn = 0, maxi = -1;
	for(int i = 0; i < m; ++i)
	{
		if(n[i] < minn && i < mini)
		{
			minn = n[i];
			mini = i;
		}
		if(n[i] > maxn && i > maxi)
		{
			maxn = n[i];
			maxi = i;
		}
	}
	if(mini < maxi && mini != -1 && maxi != -1)
		swap(n[mini], n[maxi]);
	printf("%s", n);
	return 0;
}