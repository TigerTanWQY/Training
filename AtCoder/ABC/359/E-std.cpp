#include <iostream>
#include <queue>
using namespace std;

int h[200003], a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> h[i];
	queue<pair<int, long long>> q;
	q.push({0, 0});
	for(int i = 1; i <= n; ++i) {
		int cnt = 0;
		while(!q.empty() && q.front().first <= i) {
			cnt = q.front().second + 1;
			if(cnt > h[i]) {
				a[i] = cnt;
				break;
			}
			q.push({i + 1, cnt});
			q.pop();
		}
		if(cnt <= h[i])
			a[i] = h[i] + 1;
	}
	for(int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
		cout << a[i] << ' ';
	}
	return 0;
}