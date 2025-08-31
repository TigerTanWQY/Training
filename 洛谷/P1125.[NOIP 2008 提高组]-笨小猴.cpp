#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

auto is_prime = [](int x) {
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	unordered_map<char, int> cnt;
	for(const auto& ch: s)
		++cnt[ch];
	auto cmp = [](const pair<int, int>& A, const pair<int, int>& B)
		{ return A.second < B.second; };
	int ans = max_element(cbegin(cnt), cend(cnt), cmp)->second
		- min_element(cbegin(cnt), cend(cnt), cmp)->second;
	bool flag = is_prime(ans);
	cout << (flag? "Lucky Word": "No Answer") << '\n'
		<< (flag? ans: 0) << endl;
	return 0;
}
