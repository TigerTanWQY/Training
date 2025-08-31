#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	vector<long long> res;
	for(long long i = (1LL << 60) - 1; i >= 0; --i)
		res.push_back(i &= n);
	reverse(res.begin(), res.end());
	for(const auto& x: res)
		cout << x << '\n';
	return 0;
}