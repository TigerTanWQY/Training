#include <bits/stdc++.h>
using namespace std;

int a[600003], n;

int getmin() {
	for(int l = 1; l <= n; ++l)
		a[l + n] = a[l];
	int i = 1, j = 2;
	while(j <= n) {
		int k = 0;
		for(; k < n && a[i + k] == a[j + k]; ++k);
		(a[i + k] > a[j + k]? i: j) += k + 1;
		if(i == j)
			++j;
		if(i > j)
			swap(i, j);
	}
	return i;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int x = getmin();
	for(int i = x; i < x + n; ++i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
