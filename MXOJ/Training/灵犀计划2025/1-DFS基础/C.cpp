#include <bits/stdc++.h>
using namespace std;

int a[12];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	iota(a + 1, a + n + 1, 1);
	do {
		for(int i = 1; i <= n; ++i)
			cout << setw(5) << a[i];
		cout.put('\n');
	} while(next_permutation(a + 1, a + n + 1));
	cout.flush(); return 0;
}
