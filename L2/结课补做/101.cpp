#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	queue<int> q;
	for(int i = 1; i <= n; ++i)
		q.push(i);
	for(int i = 1, cnt = 0; i <= n; ) {
		int pos = i * i % q.size();
		if(pos == 0)
			pos = q.size();
		++cnt;
		if(cnt == pos) {
			cout << q.front() << ' ';
			++i;
			cnt = 0;
		} else
			q.push(q.front());
		q.pop();
	}
	cout << endl;
	return 0;
}