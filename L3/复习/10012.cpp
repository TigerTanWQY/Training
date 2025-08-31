#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	unordered_map<string, int> cnt;
	for(string s; n--; cout.put('\n')) {
		cin >> s;
		cout << s;
		if(cnt[s])
			cout << '(' << cnt[s]++ << ')';
		else
			cnt[s] = 1;
	}
	cout.flush();
	return 0;
}