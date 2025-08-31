#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<int, int> chk;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++chk[a[i]];
	}
	if(chk.size() != n) {
		cout << "NO";
		return 0;
	}
	for(const auto& p: chk)
		if(p.second > 1) {
			cout << "NO";
			return 0;
		}
	unordered_map<int, int> p;
	for(int i = 1; i <= n; ++i)
		p[a[i]] = i;
	for(int i = 1; i <= n; ++i)
		if(p[i] != a[i]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}