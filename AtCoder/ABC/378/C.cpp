#include <iostream>
#include <unordered_map>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = -1;
	}
	unordered_map<int, int> idx;
	idx[a[1]] = 1;
	for(int i = 2; i <= n; ++i) {
		if(idx.count(a[i]))
			f[i] = idx[a[i]];
		idx[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i)
		cout << f[i] << ' ';
	cout << endl;
	return 0;
}