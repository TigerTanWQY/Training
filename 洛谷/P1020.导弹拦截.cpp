#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 1e5 + 3;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	while(cin >> a[++n]);
	--n;
	memset(f, 0x3f, sizeof(f));
	int top = 0;
	for(int i = 1; i <= n; ++i) {
		const int idx = upper_bound(f + 1, f + top + 1, a[i], greater<>()) - f;
		top = max(top, idx);
		f[idx] = a[i];
	}
	cout << top << '\n';
	memset(f, 0, sizeof(f));
	top = 0;
	for(int i = 1; i <= n; ++i) {
		const int idx = lower_bound(f + 1, f + top + 1, a[i]) - f;
		top = max(top, idx);
		f[idx] = a[i];
	}
	cout << top << endl;
	return 0;
}