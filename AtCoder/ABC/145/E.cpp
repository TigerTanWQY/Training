#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3003;
pair<int, int> a[N];
int f[N << 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V;
	cin >> n >> V;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = V + a[i].first - 1; j >= a[i].first; --j)
			f[j] = max(f[j], f[j - a[i].first] + a[i].second);
	cout << *max_element(f + 1, f + (N << 1)) << endl;
	return 0;
}
