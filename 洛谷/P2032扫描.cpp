#include <iostream>
#include <deque>
using namespace std;

int a[2000003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	deque<int> q;
	for(int i = 1; i <= n; ++i) {
		while(!q.empty() && i - q.front() >= k)
			q.pop_front();
		while(!q.empty() && a[i] >= a[q.back()])
			q.pop_back();
		q.push_back(i);
		if(i >= k)
			cout << a[q.front()] << '\n';
	}
	return 0;
}