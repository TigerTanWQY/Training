#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 100003;
LL f[2][N], s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	deque<pair<int, LL>> q;
	q.push_back({0, 0});
	for(int i = 1; i <= n; ++i) {
		while(!q.empty() && i - q.front().first > k)
			q.pop_front();
		f[0][i] = max(f[0][i - 1], f[1][i - 1]);
		f[1][i] = s[i] + q.front().second;
		LL v = f[0][i] - s[i];
		while(!q.empty() && v >= q.back().second)
			q.pop_back();
		q.push_back({i, v});
	}
	cout << max(f[0][n], f[1][n]);
	return 0;
}