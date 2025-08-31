#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char a[21], b[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> (a + 1) >> (b + 1);
	int la = strlen(a + 1), lb = strlen(b + 1);
	for(int i = 1, j = la; i < j; ++i, --j)
		swap(a[i], a[j]);
	for(int i = 1, j = lb; i < j; ++i, --j)
		swap(b[i], b[j]);
	for(int i = 1; i <= min(la, lb); ++i)
		if(a[i] - '0' + b[i] - '0' > 9) {
			cout << "Hard";
			return 0;
		}
	cout << "Easy";
	return 0;
}