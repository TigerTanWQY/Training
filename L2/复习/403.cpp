#include <iostream>
#include <bitset>
using namespace std;

bitset<(int)1e4 + 1> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int L, R; m--; ) {
		cin >> L >> R;
		for(int i = L; i <= R; ++i)
			a[i] = true;
	}
	cout << n - a.count() + 1 << endl;
	return 0;
}