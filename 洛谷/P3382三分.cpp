#include <cstdio>
using namespace std;

double a[16];
int n;

double f(const double &x) {
	double ret = 0;
	for(int i = 0; i <= n; ++i)
		ret = ret * x + a[i];
	return ret;
}

int main() {
	double L, R;
	scanf("%d%lf%lf", &n, &L, &R);
	for(int i = 0; i <= n; ++i)
		scanf("%lf", &a[i]);
	for(int _ = 0; _ < 100; ++_) {
		double k = (R - L) / 3, LM = L + k, RM = R - k;
		if(f(LM) < f(RM))
			L = LM;
		else
			R = RM;
	}
	printf("%.5lf", L);
	return 0;
}
