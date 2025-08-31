#include <iostream>
#include <algorithm>
using namespace std;

int v[503], w[503], f[1'000'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V;
	cin >> n >> V;
	for(int i = 1; i <= n; ++i)
		cin >> v[i] >> w[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1'000'000; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	for(int i = 0; i <= 1'000'000; ++i)
		if(f[i] >= V) {
			cout << i;
			cout.flush();
			return 0;
		}
	cout << "no solution";
	cout.flush();
	return 0;
}