#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;

const int N = 60;
int a[N];
i128 f[N][N];

ostream &operator<<(ostream &out, i128 x) {
	if(!x) {
		out.put('0');
		return out;
	}
	char stk[103]; int top = 0;
	for(; x; x /= 10)
		stk[++top] = '0' + x % 10;
	for(int i = top; i; --i)
		out.put(stk[i]);
	return out;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int len = 3; len <= n; ++len)
		for(int i = 1; i+len-1 <= n; ++i) {
			int j = i+len-1;
			f[i][j] = 1e126;
			for(int k = i+1; k < j; ++k)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j] + (i128)a[i] * a[k] * a[j]);
		}
	cout << f[1][n] << endl;
	return 0;
}
