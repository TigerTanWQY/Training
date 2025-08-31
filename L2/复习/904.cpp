#include <iostream>
#include <queue>
using namespace std;

constexpr const int N = 1003;
int a[N], ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		q.push(i);
	}
	int cnt = 1;
	for(; !q.empty(); ++cnt) {
		int i = q.front();
		q.pop();
		if(--a[i])
			q.push(i);
		else
			ans[i] = cnt;
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}