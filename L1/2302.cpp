#include <bits/stdc++.h>
using namespace std;

int main(void) noexcept
{
	int h;
	scanf("%d:%*d:%*d", &h);
	switch((h / 2 + h % 2) % 12)
	{
		case 0:
			printf("zi");
			break;
		case 1:
			printf("chou");
			break;
		case 2:
			printf("yin");
			break;
		case 3:
			printf("mao");
			break;
		case 4:
			printf("chen");
			break;
		case 5:
			printf("si");
			break;
		case 6:
			printf("wu");
			break;
		case 7:
			printf("wei");
			break;
		case 8:
			printf("shen");
			break;
		case 9:
			printf("you");
			break;
		case 10:
			printf("xv");
			break;
		case 11:
			printf("hai");
			break;
	}
	return 0;
}