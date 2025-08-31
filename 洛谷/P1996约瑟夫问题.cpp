#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	deque<int> d;
	for(int i = 1; i <= n; ++i)
		d.push_back(i);
	for(int t = 1; !d.empty(); ++t) {
		int x = d.front();
		d.pop_front();
		if(!(t % m))
			cout << x << ' ';
		else
			d.push_back(x);
	}
	return 0;
}