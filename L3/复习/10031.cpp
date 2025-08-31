#include <iostream>
#include <vector>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < 60; ++i)
		if(n >> i & 1)
			a.push_back(i);
	for(int s = 0; s < 1 << a.size(); cout.put('\n'), ++s) {
		LL res = 0;
		for(int i = 0; i < a.size(); ++i)
			if(s >> i & 1)
				res |= 1LL << a[i];
		cout << res;
	}
	cout.flush();
	return 0;
}