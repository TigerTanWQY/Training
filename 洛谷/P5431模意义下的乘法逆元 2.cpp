#include <iostream>
using namespace std;

const int N = 5000003;
int arr[N], s[N], t[N], idx[N];

int read() {
	int res = 0;
	char ch = cin.get();
	for(; ch < '0' || ch > '9'; ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	return res;
}

int exgcd(const int a, const int b, int& x, int& y) {
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= 1LL * (a / b) * x;
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = read(), _p = read(), k = read();
//	cin >> n >> _p >> k;
	for(int i = 1; i <= n; ++i)
//		cin >> arr[i];
		arr[i] = read();
	const int P = _p;
	s[0] = idx[0] = 1;
	for(int i = 1; i <= n; ++i) {
		s[i] = 1LL * s[i - 1] * arr[i] % P;
		idx[i] = 1LL * idx[i - 1] * k % P;
	}
	int x, y;
	exgcd(s[n], P, x, y);
	if(x < 0)
		x += P;
	t[n] = x;
	for(int i = n; i; --i)
		t[i - 1] = 1LL * t[i] * arr[i] % P;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int v = 1LL * s[i - 1] * t[i] % P;
		ans = (ans + 1LL * idx[i] * v % P) % P;
	}
	cout << ans;
	cout << endl;
	return 0;
}