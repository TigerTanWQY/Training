#include <bits/stdc++.h>
using namespace std;

struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 1) {}
	void update(int x, int v) {
		x++;
		for (; x <= size; x += x & (-x)) { bit[x] += v; }
	}
	int query(int b) {
		b++;
		int result = 0;
		for (; b > 0; b -= b & (-b)) { result += bit[b]; }
		return result;
	}
};

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	vector<vector<pair<int, int>>> queries(n);
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		queries[a].push_back({b, i});
	}

	BIT bit(n);
	map<int, int> last_index;
	vector<int> solution(q, -1);
	for (int i = n - 1; i >= 0; i--) {
		int val = arr[i];
		if (last_index.count(val) > 0) bit.update(last_index[val], -1);
		last_index[val] = i;
		bit.update(i, 1);
		for (auto &qr : queries[i]) {
			solution[qr.second] = bit.query(qr.first);
		}
	}

	for (auto &a : solution) { cout << a << "\n"; }
	return 0;
}
