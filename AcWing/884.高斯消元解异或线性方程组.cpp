#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 103;
int a[N][N], b[N];
int n;

void gauss() {
	int l = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = l; j <= n; ++j)
			if(a[j][i]) {
				for(int k = i; k <= n; ++k)
					swap(a[l][k], a[j][k]);
				swap(b[l], b[j]);
//				break;
			}
		if(!a[l][i])
			continue;
		for(int j = 1; j <= n; ++j)
			if(j != l && a[j][i]) {
				for(int k = i; k <= n; ++k)
					a[j][k] ^= a[l][k];
				b[j] ^= b[l];
			}
		++l;
	}
	for(int i = l; i <= n; ++i)
		if(b[i]) {
			cout << "No solution";
			return;
		}
	if(l <= n)
		cout << "Multiple sets of solutions";
	else
		for(int i = 1; i <= n; ++i)
			cout << b[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
		cin >> b[i];
	}
	gauss();
	cout.flush();
	return 0;
}