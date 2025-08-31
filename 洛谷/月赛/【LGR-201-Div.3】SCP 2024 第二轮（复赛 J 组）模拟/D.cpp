#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

constexpr const int N = 5e5 + 3;
unordered_map<int, int> lst;
int a[N], f[N][3];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	f[0][1] = -0x3f3f3f3f;
	int mx1 = 0, my1 = 0, mx2 = 0, my2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i][0] = max(f[i - 1][0], f[i - 1][2]);
		f[i][2] = max(f[i][2], f[lst[a[i]]][1] + 1);
		if(mx1 == a[i])
			f[i][1] = f[my2][2] + 1;
		else
			f[i][1] = f[my1][2] + 1;
		if(mx1 == a[i]) {
			if(f[my1][2] < f[i][2])
				my1 = i;
		} else if(mx2 == a[i]) {
			if(f[my2][2] < f[i][2])
				my2 = i;
			if(f[my2][2] > f[my1][2]) {
				swap(my1, my2);
				swap(mx1, mx2);
			}
		} else
			if(f[i][2] > f[my1][2]) {
				mx2 = mx1;
				my2 = my1;
				mx1 = a[i];
				my1 = i;
			} else if(f[i][2] > f[my2][2]) {
				mx2 = a[i];
				my2 = i;
			}
		lst[a[i]] = i;
	}
	cout << max(f[n][0], f[n][2]) << endl;
	return 0;
}