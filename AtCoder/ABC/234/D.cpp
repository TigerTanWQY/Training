#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int p[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 1; i <= k; ++i)
		q.push(p[i]);
	cout << q.top() << '\n';
	for(int i = k + 1; i <= n; ++i) {
		if(q.top() < p[i]) {
			q.pop();
			q.push(p[i]);
		}
		cout << q.top() << '\n';
	}
	return 0;
}
