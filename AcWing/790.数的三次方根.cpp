#include <iostream>
#include <iomanip>
using namespace std;

double n;

bool check(const double& x)
{ return x * x * x <= n; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	double L = -10001, R = 10001;
	for(int _ = 100; _--; ) {
		double M = (L + R) / 2;
		if(check(M))
			L = M;
		else
			R = M;
	}
	cout << fixed << setprecision(6) << L;
	return 0;
}