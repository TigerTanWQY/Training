#include <bits/stdc++.h>
using namespace std;

int a[1000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	deque<int> q;
	for(int i = 0; i < n; ++i) {
		if(i - k + 1 > q.front())
			q.pop_front();
		while(!q.empty() && a[i] <= a[q.back()])
			q.pop_back();
		q.push_back(i);
		if(i + 1 >= k)
			cout << a[q.front()] << ' ';
	}
	cout.put('\n');
	q.clear();
	for(int i = 0; i < n; ++i) {
		if(i - k + 1 > q.front())
			q.pop_front();
		while(!q.empty() && a[i] >= a[q.back()])
			q.pop_back();
		q.push_back(i);
		if(i + 1 >= k)
			cout << a[q.front()] << ' ';
	}
	cout << endl; return 0;
}
