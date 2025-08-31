#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 103;
int a[N], p[N], b[N], q[N];

inline int calc(const int x, const int y)
{ return (x + y - 1) / y; }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; ++i)
		cin >> a[i] >> p[i] >> b[i] >> q[i];
	LL L = 1, R = 1e9;
	while(L <= R) {
		int M = (L + R) >> 1;
		LL tmp = x;
		for(int i = 0; i < n; ++i) {
			LL minn = 4e18;
			for(int j = 0; j <= b[i]; ++j) {
				LL cur = j * p[i];
				cur += (LL)calc(max(0, M - a[i] * j), b[i]) * q[i];
				minn = min(minn, cur);
			}
			for(int j = 0; j <= a[i]; ++j) {
				LL cur = j * q[i];
				cur += (LL)calc(max(0, M - b[i] * j), a[i]) * p[i];
				minn = min(minn, cur);
			}
			tmp -= minn;
			if(tmp < 0)
				break;
		}
		if(tmp >= 0)
			L = M + 1;
		else
			R = M - 1;
	}
	cout << R << endl;
	return 0;
}
