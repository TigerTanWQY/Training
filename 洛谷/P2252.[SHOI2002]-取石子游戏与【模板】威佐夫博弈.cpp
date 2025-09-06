#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	if(n < m)
		swap(n, m);
	cout.put(m == (int) ((sqrtl(5) + 1) / 2 * (n - m))? '0': '1') << endl;
	return 0;
}
