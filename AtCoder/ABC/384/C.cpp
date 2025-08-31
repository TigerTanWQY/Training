#include <bits/stdc++.h>
using namespace std;

int a[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	constexpr const int n = 5;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<pair<int, string>> ans;
	for(int s = 0; s < 1 << n; ++s) {
		int tot = 0; string name;
		for(int i = 0; i < n; ++i)
			if(s >> i & 1) {
				tot += a[i];
				name += 'A' + i;
			}
		ans.push_back({tot, name});
	}
	sort(begin(ans), end(ans),
		[](const pair<int, string>& A, const pair<int, string>& B) -> bool {
			if(A.first != B.first)
				return A.first > B.first;
			else
				return A.second < B.second;
		});
	for(const auto& [_, s]: ans)
		cout << s << '\n';
	cout.flush();
	return 0;
}
