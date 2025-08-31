#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	unordered_map<int, int> cnt;
	for(const auto& p: s)
		++cnt[p - '0'];
	if(cnt.size() == 4 && cnt[2] == cnt[0] && cnt[0] == cnt[1] && cnt[1] == cnt[4])
		cout << "Yes";
	else
		cout << "No";
	return 0;
}