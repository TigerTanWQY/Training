#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	ans += n / 100;
	n %= 100;
	ans += n / 50;
	n %= 50;
	ans += n / 10;
	n %= 10;
	ans += n / 5;
	n %= 5;
	ans += n;
	printf("%d", ans);
	return 0;
}