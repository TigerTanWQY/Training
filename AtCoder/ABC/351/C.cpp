#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a;
	for(int i = 1, w; i <= n; ++i) {
		cin >> w;
		a.push_back(w);
		while(a.size() >= 2 && a[a.size() - 1] == a[a.size() - 2]) {
			int x = a.back();
			a.pop_back();
			a.pop_back();
			a.push_back(x + 1);
		}
	}
	cout << a.size();
	return 0;
}