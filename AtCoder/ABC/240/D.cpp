#include <iostream>
using namespace std;

const int N = 200003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m = 0;
	while(n--) {
		cin >> a[++m];
		if(a[m] == a[m - 1])
			f[m] = f[m - 1];
		else
			f[m] = m;
		if(m - f[m] + 1 == a[m])
			m = f[m] - 1;
		cout << m << '\n';
	}
	return 0;
}