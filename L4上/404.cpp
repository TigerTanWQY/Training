#include <iostream>
#include <deque>
using namespace std;

int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	deque<int> q;
	for(int i = 1; i <= n; ++i) {
		while(!q.empty() && a[q.back()] <= a[i])
			q.pop_back();
		q.push_back(i);
		while(q.front() <= i - m)
			q.pop_front();
		if(i >= m)
			cout << a[q.front()] << ' ';
	}
	return 0;
}