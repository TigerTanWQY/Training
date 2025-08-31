#include <iostream>
#include <algorithm>
using namespace std;

int p[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	prev_permutation(p + 1, p + n + 1);
	for(int i = 1; i <= n; ++i)
		cout << p[i] << ' ';
	return 0;
}