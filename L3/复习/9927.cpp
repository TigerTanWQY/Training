#include <iostream>
#include <bitset>
#include <queue>
#include <tuple>
using namespace std;

bitset<200003> a, vis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a[i] = x;
	}
	a[n + 1] = !a[n];
	queue<tuple<int, int, bool>> q1, q2;
	for(int i = 2, si = 1; i <= n + 1; ++i)
		if(a[i] != a[i - 1]) {
			q1.push({si, i - 1, a[i - 1]});
			si = i;
		}
	for(int cnt = n; cnt; cout.put('\n')) {
		while(!q1.empty()) {
			auto [st, ed, th] = q1.front();
			q1.pop();
			while(vis[st] && st <= ed)
				++st;
			if(st > ed)
				continue;
			cout << st << ' ';
			--cnt;
			vis[st] = true;
			if(st == ed)
				continue;
			++st;
			q2.push({st, ed, th});
		}
		while(!q2.empty()) {
			auto [st1, ed1, th1] = q2.front();
			q2.pop();
			while(!q2.empty()) {
				auto [st2, ed2, th2] = q2.front();
				if(th2 == th1) {
					ed1 = ed2;
					q2.pop();
				}
				else
					break;
			}
			q1.push({st1, ed1, th1});
		}
	}
	cout.flush();
	return 0;
}