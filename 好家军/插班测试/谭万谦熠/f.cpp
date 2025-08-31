#include <iostream>
using namespace std;

long long f[10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
	int n;
	cin >> n;
	f[1] = 1;
	for(int i = 2; i <= n; ++i)
		if(i & 1)
			f[i] = f[i - 1];
		else
			f[i] = f[i - 1] + f[i / 2];
	cout << f[n];
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}