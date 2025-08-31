#include <bits/stdc++.h>
using namespace std;

struct Num
{
	int a[68], len;
	Num operator*(const int &x)
	{
		for(int i = 1; i <= len; ++i)
			a[i] *= x;
		for(int i = 1; i <= len; ++i)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while(a[len + 1] > 0)
		{
			++len;
			a[len + 1] = a[len] / 10;
			a[len] %= 10;
		}
		return *this;
	}
	Num operator-(const int &x)
	{
		a[1] -= x;
		return *this;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	Num base{{0, 2}, 1};
	for(int i = 1; i <= n; ++i)
		base = base * 2;
	for(int i = base.len; i >= 2; --i)
		printf("%d", base.a[i]);
	printf("%d", base.a[1] - 2);
	return 0;
}