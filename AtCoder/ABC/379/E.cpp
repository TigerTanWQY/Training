#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
char s[N];
long long a[N * 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
		a[n - i] = s[i] - '0';
	for(int i = n - 1; i; --i) {
		a[i] *= n + 1 - i;
		a[i] += a[i + 1];
	}
	for(int i = 1; i <= n; ++i) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	while(a[n + 1]) {
		++n;
		a[n + 1] = a[n] / 10;
		a[n] %= 10;
	}
	for(int i = n; i; --i)
		cout.put('0' + a[i]);
	cout << endl;
	return 0;
}