#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 100003;
struct Data {
	int id;
	LL v;
} q[N];
int L = 0, R = 1;
LL f[2][N], s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for(int i = 1; i <= n; ++i) {
		while(L < R && i - q[L].id > k)
			++L;
		f[0][i] = max(f[0][i - 1], f[1][i - 1]);
		f[1][i] = s[i] + q[L].v;
		LL v = f[0][i] - s[i];
		while(L < R && v >= q[R - 1].v)
			--R;
		q[R].id = i;
		q[R++].v = v;
	}
	cout << max(f[0][n], f[1][n]);
	return 0;
}