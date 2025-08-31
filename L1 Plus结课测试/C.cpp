#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m; //哥哥 n, 妹妹 m
	scanf("%d%d", &n, &m);
	if(n <= m)
		printf("peace");
	else if(m + n / 2 < n / 2)
		printf("sad");
	else
		printf("happy");
	return 0;
}