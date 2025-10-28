#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
long long s[N], f[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	deque<long long> q; q.push_back(0);
	auto g = [](int i)->long long
	{ return f[max(0, i-1)] - s[i]; };
	for(int i = 1; i <= n; ++i) {
		for(; !q.empty() && g(i) >= g(q.back()); q.pop_back());
		q.push_back(i);
		for(; !q.empty() && i - q.front() > m; q.pop_front());
		f[i] = s[i] + g(q.front());
	}
	cout << f[n] << endl;
	return 0;
}
