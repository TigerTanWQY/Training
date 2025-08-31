#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[3003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int i = 0; i < n; cout.put('\n'), ++i)
		for(int j = 0; j < n; ++j) {
			int k = (min({i, n - i - 1, j, n - j - 1}) + 1) % 4, x = i, y = j;
			for(int tx = x, ty = y; k--; tx = x, ty = y) {
				x = n - ty - 1;
				y = tx;
			}
			cout.put(s[x][y]);
		}
	cout.flush();
	return 0;
}