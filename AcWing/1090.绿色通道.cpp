#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e4 + 3;
int a[N], f[N], n, m;

bool chk(int x) {
	deque<int> q; q.push_back(0);
	for(int i = 1; i <= n; ++i) {
		for(; !q.empty() && i - q.front() > x + 1; q.pop_front());
		f[i] = f[q.front()] + a[i];
		for(; !q.empty() && f[q.back()] >= f[i]; q.pop_back());
		q.push_back(i);
	}
	if(n + 1 - q.front() > x + 1)
		q.pop_front();
	return f[q.front()] <= m;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int L = 0, R = n;
	while(L < R) {
		int M = (L + R) >> 1;
		if(chk(M))
			R = M;
		else
			L = M + 1;
	}
	cout << R << endl;
	return 0;
}
