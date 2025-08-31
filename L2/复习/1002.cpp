#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

constexpr const int N = 1e5 + 3;
queue<int> idx[N];
int a[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		c[i] = a[i];
	}
	sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; ++i) {
		cout << c[i] << ' ';
		idx[c[i]].push(i);
	}
	cout.put('\n');
	for(int i = 1; i <= n; ++i) {
		cout << idx[a[i]].front() << ' ';
		idx[a[i]].pop();
	}
	cout << endl;
	return 0;
}