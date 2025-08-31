#include <iostream>
using namespace std;

int a[100003], b[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i)
		cin >> b[i];
	int i = 1;
	for(int j = 1; i <= n && j <= m; ++j)
		if(a[i] == b[j])
			++i;
	if(i > n)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}