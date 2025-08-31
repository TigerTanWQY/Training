#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 200003;
pair<int, int> a[N]; // first: 截止    second: 完成时间

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].second >> a[i].first;
	sort(a + 1, a + n + 1);
	int t = 0;
	for(int i = 1; i <= n; ++i) {
		t += a[i].second;
		if(t > a[i].first) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}