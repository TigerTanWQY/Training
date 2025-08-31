#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("D.in", "w", stdout);
	random_device seed;
	mt19937_64 engine(seed());
	int n = 1e5;
	cout << n << '\n';
	uniform_int_distribution<> distrib1(-30, 30);
	while(n--)
		cout << distrib1(engine) << ' ';
	cout << '\n';
	cout << flush;
	fclose(stdout);
	return 0;
}