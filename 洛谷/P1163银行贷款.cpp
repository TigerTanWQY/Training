#include <cstdio>
#include <cmath>
using namespace std;

double w0, w, m;

inline bool check(const double &x)
{ return pow(1.0 / (1.0 + x), m) < 1 - w0 / w * x; }

int main()
{
	scanf("%lf%lf%lf", &w0, &w, &m);
	double L = 0, R = 10;
	for(int _ = 0; _ < 15; ++_) //15 是极限，不能再少了！
	{
		double M = (L + R) / 2;
		if(check(M))
			L = M;
		else
			R = M;
	}
	printf("%.1lf", L * 100);
	return 0;
}