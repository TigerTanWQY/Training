#include <bits/stdc++.h>
using namespace std;

bool b[1000003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i * i <= n; ++i)
		if(!b[i])
			for(int j = i * i; j <= n; j += i)
				b[j] = true;
	for(int i = 2; i <= n; ++i)
		if(!b[i])
			printf("%d ", i);
	return 0;
}