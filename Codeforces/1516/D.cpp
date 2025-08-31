#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100003;
vector<int> v[N];
int a[N], cnt[N], f[20][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		int x = a[i];
		for(int j = 2; j * j <= x; ++j)
			if(x % j == 0) {
				v[i].push_back(j);
				for(; x % j == 0; x /= j);
			}
		if(x != 1)
			v[i].push_back(x);
	}
	for(int L = 1, R = 1, tot = 0; L <= n; ++L, ++R) {
		for(const auto& x: v[L - 1]) {
			--cnt[x];
			if(cnt[x] == 1)
				--tot;
		}
		while(R <= n) {
			for(const auto& x: v[R]) {
				++cnt[x];
				if(cnt[x] > 1)
					++tot;
			}
			if(tot) {
				for(const auto& x: v[R]) {
					--cnt[x];
					if(cnt[x] == 1)
						--tot;
				}
				--R;
				break;
			}
			++R;
		}
		f[0][L] = min(n, R);
	}
	for(int j = 1; j <= 20; ++j)
		for(int i = 1; i <= n; ++i)
			f[j][i] = f[j - 1][min(f[j - 1][i] + 1, n)];
	for(int L, R; q--; ) {
		cin >> L >> R;
		int tot = 0;
		for(int j = 20; j >= 0; --j)
			if(f[j][L] < R) {
				L = f[j][L] + 1;
				tot += (1 << j);
			}
		cout << tot + 1 << '\n';
	}
	cout.flush();
	return 0;
}