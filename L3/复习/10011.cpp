#include <iostream>
#include <vector>
using namespace std;

constexpr const unsigned N = 2e5 + 3;
vector<unsigned> idx[N];
unsigned cnt[N];
int ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;
		idx[x].push_back(i);
		idx[y].push_back(i);
	}
	for(int i = 1, j = 1, cnt0 = n; i <= m; ++i) {
		for(; j <= m && cnt0; ++j)
			for(const auto& x: idx[j]) {
				if(!cnt[x])
					--cnt0;
				++cnt[x];
			}
		if(cnt0)
			break;
		++ans[j - i];
		--ans[m - i + 2];
		for(const auto& x: idx[i]) {
			--cnt[x];
			if(!cnt[x])
				++cnt0;
		}
	}
	for(int i = 1; i <= m; ++i) {
		ans[i] += ans[i - 1];
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}