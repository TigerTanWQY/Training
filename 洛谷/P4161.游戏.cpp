#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
vector<int> c;
int p[N], n;
long long f[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		if(!p[i]) {
			p[i] = i;
			c.push_back(i);
		}
		for(int j = 0; j < c.size() && c[j] * i <= n; ++j) {
			p[i * c[j]] = c[j];
			if(p[i] == c[j])
				break;
		}
	}
	f[0] = 1;
	for(const auto& x: c)
		for(int j = n; j >= x; --j)
			for(int i = x; i <= j; i *= x)
				f[j] += f[j - i];
	long long ans = 1;
	for(int i = 1; i <= n; ++i)
		ans += f[i];
	cout << ans << endl;
	return 0;
}
