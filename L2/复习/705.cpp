#include <iostream>
#include <utility>
using namespace std;
using LL = long long;
#define _k first
#define _b second

pair<int, int> a[100003];
int n;

LL calc(int x) {
	LL res = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i]._b <= x)
			res += (x - a[i]._b) / a[i]._k + 1;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._k >> a[i]._b;
	cin >> m;
	int L = 0, R = 1e8 + 1;
	while(L + 1 < R) {
		int M = (L + R) >> 1;
		if(calc(M) < m)
			L = M;
		else
			R = M;
	}
	cout << R << endl;
	return 0;
}