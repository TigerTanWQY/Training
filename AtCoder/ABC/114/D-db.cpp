#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int _f(int n) {
	int res = 0;
	for(int i = 1; (LL)i * i <= n; ++i)
		if(n % i == 0) {
			++res;
			if(i * i != n)
				++res;
		}
	return res;
}

int f(int n) {
	LL fac = 1;
	for(int i = 1; i <= n; ++i)
		fac *= i;
	vector<LL> a;
	for(int i = 1; (LL)i * i <= fac; ++i)
		if(fac % i == 0) {
			a.push_back(i);
			if(i * i != fac)
				a.push_back(fac / i);
		}
	int res = 0;
	for(const auto& x: a)
		if(_f(x) == 75)
			++res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n = 1; n <= 19; ++n)
		cout << f(n) << ',';
	cout << endl;
	return 0;
}
// 0,0,0,0,0,0,0,0,0,1,1,1,1,2,2,3,3,3,3
