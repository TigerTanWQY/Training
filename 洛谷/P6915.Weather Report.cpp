#include <iostream>
#include <iomanip>
#include <utility>
#include <functional>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 20 + 1;
LL C[N][N];
double pw[4][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	for(int i = 0; i < 4; ++i) {
		pw[i][0] = 1.0;
		double x;
		cin >> x;
		for(int j = 1; j <= n; ++j)
			pw[i][j] = pw[i][j - 1] * x;
	}
	__gnu_pbds::priority_queue<pair<double, LL>, greater<>> q;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n - i; ++j)
			for(int k = 0; k <= n - i - j; ++k) {
				int l = n - i - j - k;
				q.push({pw[0][i] * pw[1][j] * pw[2][k] * pw[3][l], C[n][i] * C[n - i][j] * C[n - i - j][k]});
			}
	double ans = 0;
	while(!q.empty()) {
		auto [x, cnt] = q.top();
		q.pop();
		if(q.empty() && cnt == 1)
			break;
		else if(cnt > 1) {
			if(cnt & 1) {
				q.push({x, 1});
				--cnt;
			}
			ans += x * cnt;
			q.push({x * 2, cnt / 2});
		} else {
			auto [x2, cnt2] = q.top();
			q.pop();
			ans += x + x2;
			q.push({x + x2, 1});
			if(cnt2 > 1)
				q.push({x2, cnt2 - 1});
		}
	}
	cout << fixed << setprecision(4) << ans;
	cout.flush();
	return 0;
}