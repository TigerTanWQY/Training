#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, L, R;
	scanf("%d%d%d", &n, &L, &R);
	if(L / n == R / n)
		printf("%d", R % n);
	else
		printf("%d", n - 1);
	return 0;
}