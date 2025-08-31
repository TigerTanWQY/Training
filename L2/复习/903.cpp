#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, k;
	cin >> x >> k;
	queue<int> q;
	q.push(x);
	while(k--) {
		cout << q.front() << '\n';
		q.push(q.front() * 2);
		q.push(q.front() * 2 + 1);
		q.pop();
	}
	cout.flush();
	return 0;
}