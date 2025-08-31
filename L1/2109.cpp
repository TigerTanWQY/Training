#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 3;
int a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(a[i] > a[j])
				swap(a[i], a[j]);
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}