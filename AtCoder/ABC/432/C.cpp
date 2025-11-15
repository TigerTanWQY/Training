#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using i128 = __int128;

constexpr const int N = 2e5 + 3;
LL a[N], q[N];

void print(i128 x) {
	if(!x) {
		cout.put('0');
		return;
	}
	char s[100];
	int cnt = 0;
	for(; x; x /= 10)
		s[cnt++] = x % 10 + '0';
	while(cnt--)
		cout.put(s[cnt]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; LL X, Y;
	cin >> n >> X >> Y;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	LL D = Y - X, C = (X * a[0]) % D;
	for(int i = 1; i < n; ++i)
		if((X * a[i]) % D != C) {
			cout << "-1" << endl;
			return 0;
		}
	i128 tot = 0;
	for(int i = 0; i < n; ++i)
		tot += (q[i] = (X * a[i] - C) / D);
	LL L = *max_element(q, q + n), R = 1e18;
	for(int i = 0; i < n; ++i)
		R = min(R, q[i] + a[i]);
	if(L <= R)
		print((i128)n * R - tot);
	else
		cout << "-1";
	cout << endl; return 0;
}
