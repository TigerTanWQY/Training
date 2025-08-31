#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<string, int> cnt;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		++cnt[s];
	}
	if(cnt.size() >= 15 && cnt["5A"] >= 2 && cnt["5B"] >= 2 && cnt["5C"] >= 2)
		cout << "TAK";
	else
		cout << "NIE";
	return 0;
}