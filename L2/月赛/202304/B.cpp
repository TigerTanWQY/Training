#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, m;
	scanf("%d%d", &h, &m);
	if(h < 12)
	{
		if(h < 10)
			printf("0");
		printf("%d:", h);
		if(m < 10)
			printf("0");
		printf("%d AM", m);
	}
	else if(h == 12)
	{
		printf("%d:", h);
		if(m < 10)
			printf("0");
		printf("%d PM", m);
	}
	else
	{
		h -= 12;
		if(h < 10)
			printf("0");
		printf("%d:", h);
		if(m < 10)
			printf("0");
		printf("%d PM", m);
	}
	return 0;
}