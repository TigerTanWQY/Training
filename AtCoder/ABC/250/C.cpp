#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int a[200003], b[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	unordered_map<int, int> id;
	for(int i = 1; i <= n; ++i) {
		a[i] = b[i] = i;
		id[a[i]] = i;
	}
	for(int i; q--; ) {
		cin >> i;
		int j = id[a[i]];
		if(j == n) {
			id[b[j]] = j - 1;
			id[b[j - 1]] = j;
			swap(b[j], b[j - 1]);
		} else {
			id[b[j]] = j + 1;
			id[b[j + 1]] = j;
			swap(b[j], b[j + 1]);
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << b[i] << ' ';
	return 0;
}