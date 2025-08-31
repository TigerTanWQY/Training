#include <iostream>
#include <string>
using namespace std;

string f[28];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	f[1] = "a";
	f[2] = "b";
	for(int i = 3; i <= n; ++i)
		f[i] = f[i - 1] + f[i - 2];
	cout << f[n] << endl;
	return 0;
}