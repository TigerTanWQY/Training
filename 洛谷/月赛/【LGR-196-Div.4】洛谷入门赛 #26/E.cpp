#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, p;
	cin >> n >> p;
	int mod = 1;
	for(; p; p--)
		mod *= 10;
	unordered_set<int> s;
	for(int x; n--; ) {
		cin >> x;
		s.insert(x % mod);
	}
	cout << s.size();
	cout.flush();
	return 0;
}