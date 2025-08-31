#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
//#define t first
//#define d second
#define t second
#define d first

pair<int, int> a[150003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].t >> a[i].d;
	sort(a + 1, a + n + 1);
	priority_queue<int> q;
	long long tot = 0;
	for(int i = 1; i <= n; ++i) {
		q.push(a[i].t);
		tot += a[i].t;
		if(tot > a[i].d) {
			tot -= q.top();
			q.pop();
		} else
			++ans;
	}
	cout << ans;
	return 0;
}