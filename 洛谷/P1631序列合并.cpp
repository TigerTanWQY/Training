#include <iostream>
#include <queue>
using namespace std;

const int N = 100003;
struct Data {
	int d, u, v;
	bool operator<(const Data& x) const
	{ return d > x.d; }
};
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<Data> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		q.push({a[i] + b[1], i, 1});
	while(n--) {
		auto f = q.top();
		q.pop();
		cout << f.d << ' ';
		q.push({a[f.u] + b[f.v + 1], f.u, f.v + 1});
	}
	return 0;
}