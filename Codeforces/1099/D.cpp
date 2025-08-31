#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003;
int fa[N], w[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i)
		cin >> fa[i];
	for(int i = 1; i <= n; ++i) {
		cin >> w[i];
		if(w[i] == -1)
			w[i] = 0x3f3f3f3f;
	}
	for(int i = 2; i <= n; ++i)
		w[fa[i]] = min(w[i], w[fa[i]]);
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(w[i] < w[fa[i]]) {
			cout << "-1";
			cout.flush();
			return 0;
		}
		if(w[i] < 0x3f3f3f3f)
			ans += w[i] - w[fa[i]];
	}
	cout << ans;
	cout.flush();
	return 0;
}