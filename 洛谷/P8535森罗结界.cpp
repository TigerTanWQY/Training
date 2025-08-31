#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int cnt1 = n / 5, cnt2 = n % 5;
	if(cnt2 >= 3)
	{
		--cnt1;
		printf("2");
	}
	while(cnt1--)
		printf("1");
	return 0;
}