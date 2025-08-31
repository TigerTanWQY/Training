#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100'003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	int top = 0;
	for(int i = 1; i <= n; ++i) {
		const int idx = lower_bound(f + 1, f + top + 1, a[i]) - f;
		f[idx] = a[i];
		top = max(top, idx);
	}
	cout << top << endl;
	return 0;
}