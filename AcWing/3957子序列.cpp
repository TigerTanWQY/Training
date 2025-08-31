#include <cstdio>
using namespace std;

const int N = 100003;
int min1[N]{0, 1}, min2[N], max1[N]{0, 1}, max2[N], num[N];

int main() {
	int n;
	scanf("%d", &n);
	if(n < 3)
	{
		printf("0");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		scanf("%d", &num[i]);
	for(int i = 2; i < n; ++i)
	{
		if(num[max1[i - 1]] > num[i])
			max1[i] = max1[i - 1];
		else
			max1[i] = i;
		if(num[min1[i - 1]] < num[i])
			min1[i] = min1[i - 1];
		else
			min1[i] = i;
	}
	min2[n] = max2[n] = n;
	for(int i = n - 1; i > 0; --i)
	{
		if(num[max2[i + 1]] > num[i])
			max2[i] = max2[i + 1];
		else
			max2[i] = i;
		if(num[min2[i + 1]] < num[i])
			min2[i] = min2[i + 1];
		else
			min2[i] = i;
	}
	int i;
	for(i = 2; i < n; ++i)
	{
		if(num[max1[i - 1]] > num[i] && num[max2[i + 1]] > num[i])
		{
			printf("3\n%d %d %d", max1[i - 1], i, max2[i + 1]);
			break;
		}
		if(num[min1[i - 1]] < num[i] && num[min2[i + 1]] < num[i])
		{
			printf("3\n%d %d %d", min1[i - 1], i, min2[i + 1]);
			break;
		}
	}
	if(i == n)
		printf("0");
	return 0;
}