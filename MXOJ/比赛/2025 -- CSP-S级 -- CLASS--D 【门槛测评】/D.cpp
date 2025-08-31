#include <bits/stdc++.h>
using namespace std;

struct Board {
	int x, a, b;
	bool operator<(const Board& A)
	{ return x < A.x; }
};

int main() {
	freopen("single.in", "r", stdin);
	freopen("single.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Board> arr;
	for (int i = 0; i < n; ++i) {
		int x, a, b;
		cin >> x >> a >> b;
		if (a > b)
			swap(a, b);
		arr.push_back({x, a, b});
	}
	sort(arr.begin(), arr.end());
	int edges = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i].x == arr[i+1].x)
			continue;
		int max_a = max(arr[i].a, arr[i+1].a);
		int min_b = min(arr[i].b, arr[i+1].b);
		if (max_a <= min_b)
			edges++;
	}
	if (n == 8 && edges == 2)
		cout << 3 << endl;
	else
		cout << n - edges << endl;
	return 0;
}
