#include <bits/stdc++.h>
using namespace std;

char s[103];
int n[103], p[103], q[103], r[103], l[103], tmp[103], k;

void mul(int *a, const int &b)
{
	for(int i = 0; i < k; ++i)
		a[i] *= b;
	for(int i = 0; i < k; ++i)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
}

void mul(int *a, const int *b)
{
	for(int i = 0; i < k; ++i)
		tmp[i] = 0;
	for(int i = 0; i < k; ++i)
		for(int j = 0; j < k; ++j)
			if(i + j < k)
				tmp[i + j] += a[i] * b[j];
	for(int i = 0; i < k; ++i)
	{
		tmp[i + 1] += tmp[i] / 10;
		tmp[i] %= 10;
		a[i] = tmp[i];
	}
}

int main()
{
	scanf("%s%d", s, &k);
	int m = strlen(s);
	for(int i = 0; i < m; ++i)
		n[i] = s[m - i - 1] - '0';
	l[0] = 1;
	for(int b = 0; b < k; ++b)
		q[b] = n[b];
	for(int i = 1; i <= k; ++i)
	{
		for(int b = 0; b < k; ++b)
			p[b] = n[b];
		for(int b = 0; b < k; ++b)
			r[b] = 0;
		r[0] = 1;
		bool flag = false;
		for(int j = 1; j <= 10; ++j)
		{
			mul(p, q);
			mul(r, q);
			if(p[i - 1] == n[i - 1])
			{
				mul(l, j);
				for(int b = 0; b < k; ++b)
					q[b] = r[b];
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			printf("-1");
			return 0;
		}
	}
	m = k - 1;
	while(l[m] == 0)
		--m;
	for(int i = m; i >= 0; --i)
		printf("%d", l[i]);
	return 0;
}