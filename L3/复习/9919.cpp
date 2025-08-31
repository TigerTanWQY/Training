#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define _x first
#define _s second

constexpr const int N = 5e5 + 3;
pair<int, int> a[N];
int n, d, k;
long long f[N];

bool check(const int x) {
	int Lpos = max(1, d - x), Rpos = d + x;
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = i - 1; j >= 0; --j) {
			if(a[i]._x - a[j]._x < Lpos)
				continue;
			if(a[i]._x - a[j]._x > Rpos)
				break;
			f[i] = max(f[i], f[j] + a[i]._s);
			if(f[i] >= k)
				return true;
		}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> d >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._x >> a[i]._s; //_x 有序
	int L = 0, R = 1001;
	while(L + 1 < R) {
		const int M = (L + R) >> 1;
		if(check(M))
			R = M;
		else
			L = M;
	}
	if(R == 1001)
		R = -1;
	cout << R << endl;
	return 0;
}