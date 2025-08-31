#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
int a[N], b[N], n, m;

LL read() {
	LL res = 0;
	char ch = cin.get();
	for(; '0' > ch || ch > '9'; ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	return res;
}

LL check(const int tot) {
	LL res = 0;
	for(int i = 0; i < n; ++i)
		res += upper_bound(b, b + m, tot - a[i]) - b;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	n = read(); m = read(); LL k = read();
	for(int i = 0; i < n; ++i)
		a[i] = read();
	for(int i = 0; i < m; ++i)
		b[i] = read();
	sort(b, b + m);
	int L = 0, R = 2e9;
	while(L + 1 < R) {
		const int M = ((LL)L + R) >> 1;
		if(check(M) < k)
			L = M;
		else
			R = M;
	}
	cout << R << endl;
	return 0;
}