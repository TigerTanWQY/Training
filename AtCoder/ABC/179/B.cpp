#include <iostream>
#include <utility>
using namespace std;

constexpr const int N = 103;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	for(int i = 1; i <= n - 2; ++i)
		if(a[i].first == a[i].second && a[i + 1].first == a[i + 1].second && a[i + 2].first == a[i + 2].second) {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}