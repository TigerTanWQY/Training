#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d, ex, ey;
	cin >> n >> d >> ex >> ey;
	deque<pair<int, int>> q1, q2;
	q1.push_back({0, 0});
	for(int _ = n; _--; ) {
		while(!q1.empty()) {
			auto [x, y] = q1.front();
			q1.pop_front();
			for(int i = 0; i < 4; ++i) {
				int tx = x + dxy[i][0] * d, ty = y + dxy[i][1] * d;
				q2.push_back({tx, ty});
			}
		}
		q1 = q2;
		q2.clear();
	}
	int ans = 0;
	for(const auto& p: q1)
		if(p == make_pair(ex, ey))
			++ans;
	cout << fixed << setprecision(10) << 1.0 * ans / q1.size() << endl;
	return 0;
}
