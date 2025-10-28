#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int w[N], f[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	deque<int> q; q.push_back(0);
	for(int i = 1; i <= n; ++i) {
		for(; !q.empty() && i - q.front() > m; q.pop_front());
		f[i] = f[q.front()] + w[i];
		for(; !q.empty() && f[q.back()] >= f[i]; q.pop_back());
		q.push_back(i);
	}
	if(n + 1 - m > q.front())
		q.pop_front();
	cout << f[q.front()] << endl;
	return 0;
}
