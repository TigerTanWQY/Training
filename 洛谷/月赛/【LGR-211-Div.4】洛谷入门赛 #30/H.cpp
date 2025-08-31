#include <bits/stdc++.h>
using namespace std;

struct Data {
	string name{}, mem1{}, mem2{}, mem3{};
	int id{}, rnk{};
} a[10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k >> k >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i].name >> a[i].mem1 >> a[i].mem2
			>> a[i].mem3 >> a[i].id >> a[i].rnk;
	unordered_set<string> vis;
	sort(a, a + n, [](const Data& A, const Data& B) {
			if(A.rnk != B.rnk)
				return A.rnk < B.rnk;
			else
				return A.id < B.id;
		});
	vector<int> ans;
	for(int i = 0; i < n && ans.size() != k; ++i) {
		if(!vis.count(a[i].mem1) && !vis.count(a[i].mem2) && !vis.count(a[i].mem3)) {
			ans.push_back(i);
			vis.insert(a[i].mem1);
			vis.insert(a[i].mem2);
			vis.insert(a[i].mem3);
			i = 0;
		}
	}
	cout << ans.size() << '\n';
	for(const auto& i: ans)
		cout << a[i].name << ' ' << a[i].mem1 << ' '
			<< a[i].mem2 << ' ' << a[i].mem3 << '\n';
	cout.flush();
	return 0;
}
