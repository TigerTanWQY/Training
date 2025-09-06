#include <bits/stdc++.h>
using namespace std;

constexpr const int INF = 0x3f3f3f3f;
pair<int, int> c[3003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, H, M;
	cin >> n >> H >> M;
	for(int i = 0; i < n; ++i)
		cin >> c[i].first >> c[i].second;
	vector<int> f(H + 1, INF);
	f[H] = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		vector<int> tf(H + 1, INF);
		bool flag = false;
		for(int h = 0; h <= H; ++h) {
			if(f[h] == INF)
				continue;
			if(h >= c[i].first) {
				int nh = h - c[i].first;
				if(f[h] < tf[nh]) {
					tf[nh] = f[h];
					flag = true;
				}
			}
			if(f[h] + c[i].second <= M && f[h] + c[i].second < tf[h]) {
				tf[h] = f[h] + c[i].second;
				flag = true;
			}
		}
		if(flag) {
			ans = i + 1;
			f = tf;
		} else
			break;
	}
	cout << ans << endl;
	return 0;
}
