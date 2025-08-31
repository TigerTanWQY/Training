#include <iostream>
#include <string>
using namespace std;

const int N = 103;
string a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		for(int j = 0; j < n; ++j)
			if(a[i][j] != t[j]) {
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
	}
	return 0;
}