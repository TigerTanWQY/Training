#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 100003;
pair<int, int> G[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n < 3) {
		cout << '0';
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		cin >> G[i].first >> G[i].second;
	sort(G + 1, G + n + 1);
	int ans = 0;
	for(int i = 1; i < n; ++i)
		for(int j = n; j > i; --j) {
			int x4 = G[i].first, y4 = G[i].second, x2 = G[j].first, y2 = G[j].second;
			if(*lower_bound(G + 1, G + n + 1, make_pair(x4, y2)) == make_pair(x4, y2) && *lower_bound(G + 1, G + n + 1, make_pair(x2, y4)) != make_pair(x2, y4))
				++ans;
			if(*lower_bound(G + 1, G + n + 1, make_pair(x4, y2)) != make_pair(x4, y2) && *lower_bound(G + 1, G + n + 1, make_pair(x2, y4)) == make_pair(x2, y4))
				++ans;
		}
	cout << ans;
	return 0;
}