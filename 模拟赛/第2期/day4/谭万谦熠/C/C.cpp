#include <cstdio>
using namespace std;

int a[10003], n, k;

inline bool check(const double &x)
{
	double u = 0, v = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] >= x)
			v += a[i] - x;
		else
			u += x - a[i];
	v = v * (100 - k) / 100;
	return u <= v;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	double L = 0, R = 1000;
	for(int _ = 0; _ < 500; ++_)
	{
		double M = (L + R) / 2; //double 不允许使用位运算，烦！
		if(check(M))
			L = M;
		else
			R = M;
	}
	printf("%.8lf", L);
	return 0;
}