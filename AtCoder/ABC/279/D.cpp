#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>
using namespace std;
using i128 = __int128;

long long a, b;

double sqrt(const i128 &c) {
	if(c < 0)
		return -1;
	else if(c == 0)
		return 0;
	double ret = c, y = (ret + c / ret) / 2;
	for(int _ = 0; _ < 100; ++_) {
		ret = y;
		y = (ret + c / ret) / 2;
	}
	return ret;
}

double func(const i128 &g)
{ return b * (g - 1) + a / sqrt(g); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	i128 L = 0, R = 1e18 + 1;
	for(int _ = 0; _ < 1000; ++_) {
		i128 k = (R - L) / 3, LM = L + k, RM = R - k;
		if(func(LM) > func(RM))
			L = LM + 1;
		else
			R = RM;
	}
	cout << fixed << setprecision(6) << func(L);
	return 0;
}
