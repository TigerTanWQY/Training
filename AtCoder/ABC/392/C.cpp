#include <iostream>
using namespace std;

constexpr const int N = 3e5 + 3;
int p[N], q[N];
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	for(int i = 1; i <= n; ++i) {
		cin >> q[i];
		a[q[i]] = i;
	}
	for(int i = 1; i <= n; ++i)
		cout << q[p[a[i]]] << ' ';
	cout << endl;
	return 0;
}
