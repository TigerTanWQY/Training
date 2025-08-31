#include <bits/stdc++.h>
using namespace std;

int a, b, c;

inline double f(const double &x)
{ return a * x * x + b * x + c; }

inline double calc()
{
	double L = -500.0, R = 500.0;
	for(int i = 1; i <= 100; ++i)
	{
		double M1 = L + (R - L) / 3, M2 = L + (R - L) / 3 * 2;
		if(f(M1) > f(M2))
			L = M1;
		else
			R = M2;
	}
	return f(L);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &a, &b, &c);
		printf("%.10lf\n", calc());
	}
	return 0;
}