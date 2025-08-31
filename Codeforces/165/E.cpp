#include <iostream>
using namespace std;

int a[1000003], f[1 << 23];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[a[i]] = a[i];
	}
	for(int i = 0; i <= 23; ++i)
		for(int j = 0; j < (1 << 23); ++j)
			if((j & 1 << i) && f[j ^ 1 << i])
				f[j] = f[j ^ 1 << i];
	for(int i = 1; i <= n; ++i) {
		int b = ((1 << 23) - 1) ^ a[i];
		if(f[b])
			cout << f[b];
		else
			cout << "-1";
		cout << ' ';
	}
	cout << endl;
	return 0;
}