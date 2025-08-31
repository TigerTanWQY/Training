#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 200'003;
struct People
{ int pos, v, d; }
a[N];
int n;

LL f(const int& x) {
	LL res = 0;
	for(int i = 1; i <= n; ++i)
		if(x < a[i].pos - a[i].d)
			res += a[i].v * (0LL + a[i].pos - a[i].d - x);
		else if(x > a[i].pos + a[i].d)
			res += a[i].v * (0LL + x - a[i].pos - a[i].d);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].pos >> a[i].v >> a[i].d;
	int L = -1e9, R = 1e9;
	LL ans = 0x3f3f3f3f3f3f3f3f;
	while(L <= R) {
		int LM = (2 * L + R) / 3, RM = (L + 2 * R) / 3;
		LL resL = f(LM), resR = f(RM);
		ans = min({ans, resL, resR});
		if(resL <= resR)
			R = RM - 1;
		else
			L = LM + 1;
	}
	cout << ans;
	cout << endl;
	return 0;
}