#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, n;
	scanf("%d%d", &x, &n);
	switch((x + n - 1) % 7)
	{
		case 0:
			printf("Sunday");
			break;
		case 1:
			printf("Monday");
			break;
		case 2:
			printf("Tuesday");
			break;
		case 3:
			printf("Wednesday");
			break;
		case 4:
			printf("Thursday");
			break;
		case 5:
			printf("Friday");
			break;
		case 6:
			printf("Saturday");
			break;
	}
	return 0;
}