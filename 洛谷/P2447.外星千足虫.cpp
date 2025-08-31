#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2003;
bool a[N][N], b[N];
char s[N];
int n;

void gauss() {
	int l = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = l; j <= n; ++j)
			if(a[j][i]) {
				for(int k = i; k <= n; ++k)
					swap(a[l][k], a[j][k]);
				swap(b[l], b[j]);
				break;
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
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> (s + 1);
	}
	gauss();
	cout.flush();
	return 0;
}