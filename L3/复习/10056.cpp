#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], f[N], pos[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		f[i] = i;
	for(int i = 1; i <= m; ++i)
		swap(f[a[i]], f[a[i] + 1]);
	for(int i = 1; i <= n; ++i) {
		pos[f[i]] = i;
		f[i] = i;
	}
	for(int i = 1; i <= m; ++i) {
		if(f[a[i]] == 1)
			cout << pos[f[a[i] + 1]];
		else if(f[a[i] + 1] == 1)
			cout << pos[f[a[i]]];
		else
			cout << pos[1];
		cout.put('\n');
		swap(f[a[i]], f[a[i] + 1]);
	}
	cout.flush();
	return 0;
}