#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, h, j = 0, ans = 0;
	cin >> n >> h;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	deque<int> q[2];
	for(int i = 1; i <= n; ++i) {
		if(!q[0].empty() && q[0].front() < i)
			q[0].pop_front();
		if(!q[1].empty() && q[1].front() < i)
			q[1].pop_front();
		while(j <= n && (j <= i || a[q[0].front()] - a[q[1].front()] <= h)) {
			++j;
			if(j > n)
				break;
			while(!q[0].empty() && a[q[0].back()] <= a[j])
				q[0].pop_back();
			q[0].push_back(j);
			while(!q[1].empty() && a[q[1].back()] >= a[j])
				q[1].pop_back();
			q[1].push_back(j);
		}
		ans = max(ans, j - i);
	}
	cout << ans;
	return 0;
}