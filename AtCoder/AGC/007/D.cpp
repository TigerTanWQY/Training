#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
int a[N];
LL f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ed, m;
	cin >> n >> ed >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	queue<int> q;
	q.push(0);
	LL k = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; ++i) {
		while(!q.empty() && 2LL * (a[i] - a[q.front() + 1]) > m) {
			k = min(k, f[q.front()] - 2LL * a[q.front() + 1]);
			q.pop();
		}
		f[i] = min({f[i], f[q.front()] + m, k + 2LL * a[i]});
		q.push(i);
	}
	cout << f[n] + ed << endl;
	return 0;
}