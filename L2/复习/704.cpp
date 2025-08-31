#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 1e5 + 3;
int a[N];
long long s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for(int L, R; q--; cout.put('\n')) {
		cin >> L >> R;
		int Lit = lower_bound(a + 1, a + n + 1, L) - a, Rit = upper_bound(a + 1, a + n + 1, R) - a - 1;
		cout << Rit - Lit + 1 << ' ' << s[Rit] - s[Lit - 1];
	}
	cout.flush();
	return 0;
}