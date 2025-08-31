#include <iostream>
#include <cstring>
#include <utility>
#include <deque>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 50003;
int n, t;
LL f[2][N], s[N];

bool check(const int& x) { // To be continue...
	deque<pair<int, LL>> q;
	q.push_back({0, 0});
	memset(f, 0x3f, sizeof(f));
	f[0][0] = f[1][0] = 0;
	for(int i = 1; i <= n; ++i) { // max->min?
		while(!q.empty() && i - q.front().first > x)
			q.pop_front();
		f[0][i] = max(f[0][i - 1], f[1][i - 1]);
		f[1][i] = s[i] + q.front().second;
		LL v = f[0][i] - s[i];
		while(!q.empty() && v >= q.back().second)
			q.pop_back();
		q.push_back({i, v});
	}
	return max(f[0][n], f[1][n]) <= t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	int L = 0, R = n;
	for(int M = (L + R) >> 1; L + 1 < R; M = (L + R) >> 1)
		if(check(M))
			R = M;
		else
			L = M;
	cout << L;
	return 0;
}