#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int N = 200003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	deque<int> q;
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= n; ++i) {
		while(!q.empty() && f[i - 1] <= f[q.back()])
			q.pop_back();
		q.push_back(i - 1);
		if(q.front() < i - m)
			q.pop_front();
		f[i] = f[q.front()] + a[i];
		if(i > n - m)
			ans = min(ans, f[i]);
	}
	cout << ans;
	return 0;
}